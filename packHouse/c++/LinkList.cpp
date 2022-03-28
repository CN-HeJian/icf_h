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

//判断链表是否有环路

#include <bits/stdc++.h>
using namespace std;

struct listNode{
    int val;
    listNode* next;
    listNode(int val_):val(val_),next(nullptr){}
};

int main(){
    listNode* headA = new listNode(-1);
    listNode* node1 = new listNode(1);
    listNode* node2 = new listNode(2);
    listNode* node3 = new listNode(3);
    listNode* node4 = new listNode(4);

    headA->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;


    listNode* slow = headA;
    listNode* fast = headA;

    listNode* res = nullptr;

    while(true){
        if(fast->next == nullptr || fast->next->next ==nullptr){
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            res = slow;
            break;
        }
    }

    slow = headA;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    res = slow;

    if(res!=nullptr){
        cout<<"node val is "<<res->val<<endl;
    }else{
        cout<<"none"<<endl;
    }

}