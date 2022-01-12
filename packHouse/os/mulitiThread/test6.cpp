// Copyright 2022 icf
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

#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

sem_t s;

void* child(void * arg){
    printf("child\n");
    sleep(5);//5 second
    sem_post(&s);
    return NULL;
}


int main(){
    sem_init(&s,-0,0);
    printf("parent:begin\n");
    pthread_t c;
    pthread_create(&c,NULL,child,NULL);
    sem_wait(&s);
    printf("parent:end\n");
}

