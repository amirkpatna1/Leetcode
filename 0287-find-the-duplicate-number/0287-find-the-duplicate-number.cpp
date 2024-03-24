class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int slow=v[0],fast=v[0];
        do{
            slow=v[slow];
            fast=v[v[fast]];
        } while(slow!=fast);
        
        if(slow==v[0]) return v[0];
        slow=v[0];
        while(slow!=fast){
            slow=v[slow];
            fast=v[fast];
        }
        return slow;
    }
};