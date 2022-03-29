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

//相交链表

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int _val):val(_val),next(nullptr){}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* p1 = headA;
    ListNode* p2 = headB;

    while(p1!=p2){
        p1 = (p1==nullptr) ? headB:p1->next;
        p2 = (p2==nullptr) ? headA:p2->next; 
    }

    return p1;
}

int main(){
    ListNode* headA = new ListNode(-1);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    headA->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;



    ListNode* headB = new ListNode(-2);
    ListNode* node6 = new ListNode(6);
    headB->next = node6;
    node6->next = node3;

    ListNode* r = getIntersectionNode(headA,headB);
    
    cout<<r->val<<endl;
}


