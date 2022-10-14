class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)return NULL;
        ListNode *slow=head,*fast=head,*u=head;
        while(fast && fast->next){
            u=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        u->next=slow->next;
        return head;
    }
};