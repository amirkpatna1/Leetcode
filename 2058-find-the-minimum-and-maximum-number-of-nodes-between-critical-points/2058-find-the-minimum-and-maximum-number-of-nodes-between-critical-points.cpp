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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans={100000000,-1};
        int p=-1,i=0,pc=-1;
        ListNode *curr=head,*prev=NULL;
        while(curr){
            if(prev && curr->next && ((curr->val>prev->val && curr->next->val<curr->val) || (curr->val<prev->val && curr->next->val>curr->val))){
                ans[0]=min(ans[0],pc!=-1?i-pc:ans[0]);
                ans[1]=max(ans[1],p!=-1?i-p:-1);
                if(p==-1)
                    p=i;
                pc=i;
            }
            prev=curr;
            curr=curr->next;
            i++;
        }
        ans[0]=ans[0]==1e8?-1:ans[0];
        return ans;
    }
};