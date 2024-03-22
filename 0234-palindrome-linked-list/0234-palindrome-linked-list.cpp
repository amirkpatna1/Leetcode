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
    bool ans=true;
    void func(ListNode* head,ListNode* &curr){
        if(!head || !ans)return ;
        func(head->next,curr);
        if(head->val!=curr->val) ans=false;
        curr=curr->next;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *curr=head;
        func(head,curr);
        return ans;
    }
};