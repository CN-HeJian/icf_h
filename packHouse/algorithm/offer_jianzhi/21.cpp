#include <iostream>
using namespace std;

struct ListNode{
    ListNode* next;
    int val;
    ListNode(int val_):next(nullptr),val(val_){}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    //
    ListNode* dummy =  new ListNode(-1);
    dummy->next = head;
    
    //
    ListNode* slow = dummy;
    ListNode* fast = head;
    
    for(int i=0;i<n;i++){
        if(fast!=nullptr){
            fast = fast->next;
        }else{
            return nullptr;
        }
    }
    
    while(fast!=nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    
    slow->next = slow->next->next;
    
    return dummy->next;
}
    
int main(void){
    ListNode* head = new ListNode(-1);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;
    
    ListNode* h =  removeNthFromEnd(head,1);
    
    while(h!=nullptr){
        cout<<h->val<<endl;
        h = h->next;
    }
    
}
