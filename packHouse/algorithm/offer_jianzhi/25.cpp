//链表相加

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* h1){
        ListNode* dummy =  nullptr;
        ListNode* pre = dummy;
        ListNode* cur = h1;
        while(cur){
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }   
        return pre;     
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //先反转一次
        ListNode* p1 = reverse(l1);
        ListNode* p2 = reverse(l2);


        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int carry = 0;
        while(p1 || p2 || carry){
            int t1 = 0;
            if(p1){
                t1 = p1->val;
                p1 = p1->next;
            }
            int t2 = 0;
            if(p2){
                t2 = p2->val;
                p2 = p2->next;
            }
            int sum = carry+ t1 + t2;
            ListNode* t = new ListNode(sum%10);
            cur->next = t;
            cur = t;
            carry = sum/10;
        }
        cur->next = nullptr;
        return reverse(dummy->next);
    }
};
