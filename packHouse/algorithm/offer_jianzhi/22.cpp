#include <iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int val_):next(nullptr),val(val_){}
};

// 面试的时候可能会问你的推导过程
// a + n(b+c) = 2*(a+b)
// (n-1)*b + nc = a
// a = (n-1)(b+c)+c

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(true){
        // 这儿写错过！！！ 手误写成可 && 
        if(fast==nullptr||fast->next==nullptr){  
            return nullptr;
        }
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    
    
    slow = head;
    
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
    
} 

int main(){
    ListNode* head = new ListNode(-1);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    
    ListNode* h = detectCycle(head);
    
    cout<<h->val<<endl;
    return 0;
}
