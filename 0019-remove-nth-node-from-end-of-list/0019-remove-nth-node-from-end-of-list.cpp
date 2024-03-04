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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node=head,*root=head,*u=NULL;
        int temp=n;
        while(temp--){
            node=node->next;
        }
        while(node){
            u=root;
            node=node->next;
            root=root->next;
        }
        if(!u)return head->next;
        u->next=root->next;
        return head;
    }
};