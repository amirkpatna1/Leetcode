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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* getMidNode(ListNode* head) {
        ListNode *fast = head,*slow = head,*u = head;
        while(fast && fast->next) {
            u = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return u;
    }
    
    TreeNode* generateTree(ListNode* head) {
        if(!head) return NULL;
        ListNode *midNode = getMidNode(head);
        ListNode *nextNode = midNode->next;
        midNode->next = NULL;
        if(!nextNode) return new TreeNode(midNode->val);
        TreeNode *root = new TreeNode(nextNode->val);
        root->left = generateTree(head);
        root->right = generateTree(nextNode->next);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return generateTree(head);
    }
};