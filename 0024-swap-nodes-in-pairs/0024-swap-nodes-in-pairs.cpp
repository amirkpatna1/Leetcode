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
    
    void swapNodes(ListNode *prevNode,ListNode *currNode) {
        if(!currNode->next) return ;
        ListNode *nextNode = currNode->next->next;
        prevNode->next = currNode->next;
        currNode->next->next = currNode;
        currNode->next = nextNode;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!(head && head->next)) return head;
        ListNode *start = new ListNode(),*prev = start;
        while(head && head->next) {
            swapNodes(prev,head);
            prev = head;
            head = head->next;
        }
        return start->next;
    }
};