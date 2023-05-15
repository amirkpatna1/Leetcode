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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fromStart=head,*fromEnd=head,*temp;
        while(k-->1)fromStart=fromStart->next;
        temp=fromStart;
        while(temp->next)temp=temp->next,fromEnd=fromEnd->next;
        // cout<<fromStart->val<<" "<<fromEnd->val<<endl;
        swap(fromStart->val,fromEnd->val);
        return head;
    }
};