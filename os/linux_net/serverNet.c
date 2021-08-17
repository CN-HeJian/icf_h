#include "stdio.h"
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
    uint16_t host_port = 0x1234;
    uint32_t host_addr = 0x12345678;
#ifdef P
    printf("host_port %#x host_addr %#x\n",host_port,host_addr);
#endif

    uint16_t net_port = htons(host_port);
    uint32_t net_addr = htonl(host_addr);
#ifdef P
    printf("net_port %#x, net_addr %#x\n",net_port,net_addr);
#endif

    uint16_t c_host_port = ntohs(net_port);
    uint32_t c_host_addr = ntohl(net_addr);
#ifdef P
    printf("c_host_port %#x c_host_addr %#x\n",c_host_port,c_host_addr);
#endif

    const char *ip1 = "192.168.130.60";
    const char *ip2 = "192.168.130.256";

    in_addr_t  in_net_addr1 = inet_addr(ip1);
#ifdef P
    if(in_net_addr1 == INADDR_NONE){
        printf("transf failed");
    }else{
        printf("net addr seq: %#x\n",in_net_addr1);
    }
#endif

in_addr_t  in_net_addr2 = inet_addr(ip2);
#ifdef P
    if(in_net_addr2 == INADDR_NONE){
        printf("transf failed\n");
    }else{
        printf("net addr seq: %#x\n",in_net_addr2);
    }
#endif

//------------------------------------------------ready sockaddress----------------------------------
    const char *ip = "127.0.0.1";
    int server_port = 0x1235;
    struct sockaddr_in address;
    memset(&address,0,sizeof (address));
    address.sin_family = AF_INET;
    address.sin_port = htons(server_port);
    address.sin_addr.s_addr = inet_addr(ip);
//------------------------------------------------create socket------------------------------------- buy phone
    int server_socket;
    server_socket = socket(PF_INET,SOCK_STREAM,0); //mobile phone
    if(server_socket==-1){
        perror("socket create error");
    }
    printf("socket is %d\n",server_socket);
//--------------------------------------------------bind socket-------------------------------------- phone card
    int r_bind = bind(server_socket,(struct sockaddr*)&address,sizeof(address));
    if(r_bind==-1){
        perror("bind error\n");
        exit(1);
    }
    printf("r_bind success\n");
//-------------------------------------------------listen-------------------------------------------- lsiten phone
    int r_lsiten = listen(server_socket,5);
    if(r_lsiten == -1){
        perror("listen failed\n");
        exit(1);
    }
    printf("listen success\n");
//--------------------------------------------------accept------------------------------------------- pick up the phone
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    while(1){
        printf("wait for connect\n");
        int connfd = accept(server_socket,(struct sockaddr*)&client_addr,&client_addr_len);
        if(connfd == -1){
            perror("accept failed\n");
            exit(1);
        }
        else{
            printf("accept ok\n");
        }

        printf("connect from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        char time_message[100];
        timer_t now_time = (timer_t)time(NULL);
        snprintf(time_message, sizeof(time_message), "%.24s\n", ctime((const timer_t)&now_time));

        send(connfd, time_message, sizeof(time_message), 0);
        close(connfd);
    }
}