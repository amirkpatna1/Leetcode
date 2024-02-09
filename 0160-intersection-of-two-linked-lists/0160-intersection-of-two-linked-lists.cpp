/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA=headA,*currB=headB;
        int cnt=0;
        while(currA!=currB && cnt<2){
            currA=currA->next;
            currB=currB->next;
            if(!currA)currA=headB,cnt++;;
            if(!currB)currB=headA;
        }
        return cnt==2?NULL:currA;
    }
};