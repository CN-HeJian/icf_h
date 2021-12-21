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
#include <vector>
using namespace std;

//生成随机数[1,100]
int rand_100(){
    return (rand()%100-1+1)+1;
}

int main(){
    //记录生成的随机数的个数
    vector<int> sum_cnt(100,0);
    //总的随机次数
    long cnt = 0;
    //生成随机数
    while(1){
        //[100 * 99] + 100 = 9900 + 100 = 10000 -- 1
        long b = 100*(rand_100()-1)+rand_100();
        while(b>9940){
            b = 100*(rand_100()-1)+rand_100();
        }
        int target = b%70+1;
        
        cnt++;
        sum_cnt[target]++;

        if(cnt>100000000){
            break;
        }
    }
    //输出各个随机数的个数
    for(int i=0;i<sum_cnt.size();i++){
        cout<<sum_cnt[i]<<endl;
    }
}