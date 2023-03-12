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

struct node{
    bool operator()(ListNode* l1,ListNode* l2) const{
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
// min heap to sort the linked lists by their head node's value
priority_queue<ListNode*, vector<ListNode*>, node> pq;
for (int i = 0; i < lists.size(); i++) {
if (lists[i]) pq.push(lists[i]);
}
// create a dummy head node to make the implementation easier
ListNode* dummy = new ListNode();
ListNode* tail = dummy;
while (!pq.empty()) {
// get the linked list with the smallest head node
ListNode* smallest = pq.top();
pq.pop();
// append it to the merged linked list
tail->next = smallest;
tail = tail->next;
// add the next node of the linked list to the min heap if it exists
if (smallest->next) pq.push(smallest->next);
}
// return the merged linked list after removing the dummy head node
ListNode* res = dummy->next;
delete dummy;
return res;
    }
};