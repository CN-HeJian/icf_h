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
#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define AO_SWAP(ptr, value)           ((__typeof__(*(ptr)))__sync_lock_test_and_set((ptr), (value)))


struct SpinLock{
    //0表示无
    uint64_t locked;
    char * name;
};

void acquire(struct SpinLock* lk){

    //先将1放进去,查看返回值，查看是否有锁，如果返回为0，while条件为false，则会跳出循环
    //返回值是原来锁里面拥有的值
    while(AO_SWAP(&lk->locked,1)!=0);

    __sync_synchronize();
}

void release(struct spinlock* lk){

    __sync_synchronize();

    __sync_lock_release(&lk->locked);
}


