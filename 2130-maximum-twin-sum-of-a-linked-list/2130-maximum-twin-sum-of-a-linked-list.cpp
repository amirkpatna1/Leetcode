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
    
    ListNode *rev(ListNode* root) {
        ListNode *curr = root,*next, *prev = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *fast = head, *slow = head, *prev;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        prev = rev(slow);
        int ans = 0;
        while(prev) {
            ans = max(ans,prev->val + head->val);
            prev = prev->next;
            head = head->next;
        }
        return ans;
    }
};