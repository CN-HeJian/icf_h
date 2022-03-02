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

using namespace std;

class Singleton{
public:
    ~Singleton(){
        cout<<"constructure"<<endl;
    }
    
    Singleton(const Singleton& rhs)=delete;
    Singleton& operator=(const Singleton &rhs) =delete;

    static Singleton& getInstace(){
        static Singleton instance;
        return instance;
    }

private:
    Singleton(){
        cout<<"descontructure"<<endl;
    }

};

int main(int argc, char *argv[])
{
    Singleton& instance_1 = Singleton::getInstace();

    cout<<" instance1: "<<&instance_1<<endl;

    Singleton& instance_2 = Singleton::getInstace();

    cout<<" instance2: "<<&instance_2<<endl;

    return 0;
}

