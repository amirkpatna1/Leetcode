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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *prev = new ListNode(0);
        ListNode *res = prev;
        prev->next = head;
        int s = 0;
        unordered_map<int, ListNode*> mp;
        while(res) {
            s += res->val;
            if(mp.count(s)) {
                res = mp[s]->next;
                int p = s + res->val;
                while(p != s) {
                    mp.erase(p);
                    res = res -> next;
                    p += res -> val;
                }
                mp[s]->next = res->next;
            } else {
                mp[s] = res;
            }
            res = res->next;
        }
        return prev->next;
    }
};