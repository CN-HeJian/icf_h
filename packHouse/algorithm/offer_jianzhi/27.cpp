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

#include <iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int val_):next(nullptr),val(val_){}
};

ListNode* reverse(ListNode* head){
    ListNode* dummy = nullptr;
    ListNode* pre = dummy;
    ListNode* cur = head;

    while(cur){
        ListNode* t = cur->next;
        cur->next = pre;
        pre =cur;
        cur = t;
    }

    return pre;
}

ListNode* find(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    //在这儿一定要判断接下来不是空，接下来的接下来不是空
    while(fast->next !=nullptr && fast->next->next!=nullptr){
        fast =fast->next->next;
        slow = slow->next;
    }
    return slow;
}


bool isPanic(ListNode* head){
    ListNode* endHalf = find(head);
    ListNode* newHead = reverse(endHalf->next);
    
    

    int res = true;
    ListNode* p = head;
    while(newHead){
        if(newHead->val == p->val){
            newHead = newHead->next;
            p=p->next;
        }else{
           res = false;
           break;
        }
    }

    endHalf->next = reverse(newHead);


    return res;
}




int main(){
    ListNode* head = new ListNode(-1);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(-1);
    
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;
    
    bool res = isPanic(head);

    cout<<res<<endl;

    return 0;
}

