// Copyright 2021 icf
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>
#include <iostream>
using namespace std;

#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 10

int setNoBlocking(int fd){
    int old_option = fcntl(fd,F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;
}

void addfd(int epollfd,int fd,bool enable_et){
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    if(enable_et){
        event.events |= EPOLLET;
    }
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
    setNoBlocking(fd);
}

void lt(epoll_event* events,int number,int epollfd,int listenfd){
    char buf[BUFFER_SIZE];
    for(int i=0;i<number;i++){
        int sockfd = events[i].data.fd;
        cout<<"sockfd: "<<sockfd<<"  listenfd: "<<listenfd<<endl;
        if(sockfd == listenfd){
            struct sockaddr_in client_address;
            socklen_t client_addrlength = sizeof(client_address);
            int connfd  = accept(listenfd,(struct sockaddr*)&client_address,&client_addrlength);
            addfd(epollfd,connfd,false);
        }else if(events[i].events&EPOLLIN){
            printf("lt event trigger once\n");
            memset(buf,'\0',BUFFER_SIZE);
            int ret = recv(sockfd,buf,BUFFER_SIZE-1,0);
            if(ret<=0){
                close(sockfd);
                continue;
            }
            printf("get %d bytes of content: %s\n",ret,buf);
        }else{
            printf("something else happened\n");
        }
    }
}

void et(epoll_event* events,int number,int epollfd,int listenfd){
    char buf[BUFFER_SIZE];
    for(int i=0;i<number;i++){
        int sockfd = events[i].data.fd;
        cout<<"sockfd: "<<sockfd<<"  listenfd: "<<listenfd<<endl;
        if(sockfd==listenfd){
            struct sockaddr_in client_address;
            socklen_t client_addrlength = sizeof(client_address);
            int connfd = accept(listenfd,(struct sockaddr*)&client_address,&client_addrlength);
            addfd(epollfd,connfd,true);
        }else if(events[i].events&EPOLLIN){
            printf("et event trigger once\n");
            int ret = recv(sockfd,buf,BUFFER_SIZE-1,0);
            if(ret<0){
                if((errno==EAGAIN)||(errno==EWOULDBLOCK)){
                    printf("read later\n");
                    break;
                }
                close(sockfd);
                break;
            }else if(ret==0){
                close(sockfd);
            }else{
                printf("get %d bytes of content: %s\n",ret,buf);
            }
        }else{
            printf("somthing else happened\n");
        }
    }
}

int main(int argc,char* argv[]){
    if(argc<2){
        printf("usage: %s ip_address port_number\n",basename(argv[0]));
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi(argv[2]);

    int ret = 0;
    struct sockaddr_in address;
    bzero(&address,sizeof(address));

    address.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&address.sin_addr);
    address.sin_port = htons(port);

    int listenfd = socket(PF_INET,SOCK_STREAM,0);
    assert(listenfd>=0);

    ret = bind(listenfd,(struct sockaddr*)&address,sizeof(address));
    assert(ret!=-1);

    ret = listen(listenfd,5);
    assert(ret!=-1);

    epoll_event events[MAX_EVENT_NUMBER];
    int epollfd = epoll_create(5);
    assert(epollfd!=-1);
    addfd(epollfd,listenfd,true);

    while(1){
        int ret = epoll_wait(epollfd,events,MAX_EVENT_NUMBER,-1);
        if(ret<0){
            printf("epoll failture\n");
            break;   
        }
        lt(events,ret,epollfd,listenfd);
        //et(events,ret,epollfd,listenfd);
    }

    close(listenfd);
    return 0;

}
