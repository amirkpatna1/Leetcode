/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* rev(ListNode* head){
        ListNode *curr=head,*prev=NULL,*next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(!head->next)return ;
        ListNode *slow=head,*fast=head->next;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *mid=slow->next;
        slow->next=NULL;
        mid=rev(mid);
        fast=mid;
        slow=head;
        while(slow && fast){
            ListNode* next=slow->next;
            ListNode* nextFast=fast->next;
            slow->next=fast;
            fast=nextFast;
            slow=slow->next;
            if(!next){
                break;
            }
            slow->next=next;
            slow=next;
        }
    }
};