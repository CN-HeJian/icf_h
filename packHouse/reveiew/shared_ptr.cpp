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

class SharedPtr{

public:

    SharedPtr(){}

    SharedPtr(int * ptr):source(ptr),m_count(nullptr){
        addrefCount();
    }

    SharedPtr(const SharedPtr* p){
        source =  p->source;
        m_count = p->m_count;
        addrefCount();
    }


    ~SharedPtr(){
        decrefCount();
    }

    void addrefCount(){
        if(m_count){
            (*m_count)++;
        }else{
            m_count = new int(0);
            (*m_count)++;
        }
    }

    int decrefCount(){
        if(m_count){
            (*m_count)--;
            if(*m_count==0){
                source = nullptr;
                m_count = nullptr;
                delete source;
                delete m_count;
            }
        }else{
            return -1;
        }
    }

private:

    int* source;
    int* m_count;


};
