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


#include <iostream>
using namespace std;

#include <bits/socket.h>

union
{
    short value;
    char  bytes[sizeof(short)];
} test;

int main(int argc,char* argv[]){
    short val = 0x0102;  //高字节放在高地址上，低字节放在地址上！！！
    test.value = val;

    if(test.bytes[0]== 1  && test.bytes[1] == 2){
        // 
        std::cout<<"Big endia"<<std::endl;
    }

    if(test.bytes[0]== 2 && test.bytes[1] == 1){
        //
        std::cout<<"Small endia"<<std::endl;
    }

    return 0;
}
