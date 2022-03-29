#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    pair<ListNode*,ListNode*> reverse(ListNode* start,ListNode* end){
        ListNode* dummy = nullptr;
        ListNode* cur = start;
        ListNode* pre = dummy;
        while(pre!=end){
            ListNode* t = cur->next;
            cur->next = pre;
            pre= cur;
            cur = t;
        }
        return {end,start};
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        int i = 0;

        ListNode* l_pre = dummy;
        for(int i=0;i<left-1;i++){
            l_pre =  l_pre->next;
        }

        ListNode* r = l_pre;
        for(int i=0;i<right-left+1;i++){
            r = r->next;
        }

        ListNode* r_next = r->next;


        pair<ListNode*,ListNode*> p = reverse(l_pre->next,r);

        l_pre->next = p.first;
        p.second->next = r_next;

        return dummy->next;
    }
};
