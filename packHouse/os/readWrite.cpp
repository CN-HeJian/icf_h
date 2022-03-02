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
#include <bits/stdc++.h>
#include <iostream>


using namespace std;

class ReadWriteLock{

private:
    std::mutex readMtx;

    std::mutex writeMtx;

    int readCnt;

public:

    ReadWriteLock():readCnt(0){}

    void readLock(){
        readMtx.lock();

        if(++readCnt==1){
            writeMtx.lock();
        }


        readMtx.unlock();

    }

    void readUnlock(){
        readMtx.unlock();
        
        if(--readCnt==0){
            writeMtx.unlock();
        }

        readMtx.unlock();
    }

    void writeLock(){
        writeMtx.lock();
    }

    void writeUnlock(){
        writeMtx.unlock();
    }

};


volatile int var = 10; // 保持变量 var 对内存可见性，防止编译器过度优化
readWriteLock rwLock; // 定义全局的读写锁变量

void Write() {
    rwLock.writeLock();
    var += 10;
    std::cout << "write var : " << var << std::endl;
    rwLock.writeUnlock();
}

void Read() {
    rwLock.readLock();
    std::cout << "read var : " << var << std::endl;
    rwLock.readUnlock();
}

int main() {
    std::vector<std::thread> writers;
    std::vector<std::thread> readers;
    for (int i = 0; i < 10; i++) {  // 10 个写线程
        writers.push_back(std::thread(Write));  // std::thread t 的写法报错
    }
    for (int i = 0; i < 100; i++) {   // 100 个读线程
        readers.push_back(std::thread(Read));
    }
    for (auto& t : writers) {   // 写线程启动
        t.join();
    }
    for (auto& t : readers) {   // 读线程启动
        t.join();
    }
    std::cin.get();
}