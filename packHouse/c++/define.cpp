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

#define MIN(A,B) (A)<(B)?(A):(B)

#define SQUARE(A,B) ({__typeof__(A) __a = (A);__typeof__(B) __b = (B);(__a)*(__a)+(__b)*(__b);})

//#define SQUARE(A,B) ((A)*(A))+((B)*(B))

#include <iostream>

int main(){
    // float a = 1.0f;
    // float b = MIN(++a,1.5f);
    // std::cout<<b<<std::endl;

    // float c = 1.0f;
    // float d = MIN(c++,1.5f);
    // std::cout<<d<<std::endl;
    
    // int e = SQUARE(1,3);
    // std::cout<<e<<std::endl;

    int f = 1,g=3;
    std::cout<<f<<std::endl;
    int h = SQUARE(++f,++g);
    std::cout << f<<std::endl;
    std::cout<<h<<std::endl;

    // int i = 1;
    // int j = (++i) * (++i);
    // std::cout<<j<<std::endl;
}