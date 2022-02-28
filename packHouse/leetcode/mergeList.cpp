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

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int _val):val(_val),next(nullptr){}
};


ListNode* mergeList(ListNode* l1,ListNode* l2){
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;

    while(l1&&l2){
        if(l1->val<l2->val){
            cur->next = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;  //这儿忘记了，就会返回一个4
    }

    if(l1){  //这儿写成while就会一直死循环
        cur->next = l1;
    }

    if(l2){
        cur->next = l2;
    }

    return dummy->next;
}

int main(){
    ListNode* head1 = new ListNode(-1);
    ListNode* head2 = new ListNode(0);

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    head1->next = node1;
    node1->next = node3;
    node3->next = nullptr;

    head2->next = node2;
    node2->next = node4;
    node4->next = nullptr;

    ListNode* r =  mergeList(head1,head2);

    while(r){
        cout<<r->val<<" ";
        r = r->next;
    }
    
    cout<<" "<<endl;

}