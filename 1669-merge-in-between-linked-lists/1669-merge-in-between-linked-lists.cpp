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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *left = NULL, *right = NULL;
        ListNode *curr = list1;
        int cnt = 1;
        while(curr && cnt <= b + 1) {
            if(cnt == a) left = curr;
            else if(cnt == b + 1) right = curr;
            curr = curr->next;
            cnt += 1;
        }
        ListNode *last = list2;
        while(last && last->next) {
            last = last->next;
        }
        if(a == 0) last->next = right->next;
        else {
            left->next = list2;
            last->next = right->next;
            return list1;
        }
        return list2;
    }
};