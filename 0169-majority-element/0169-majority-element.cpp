class Solution {
public:
    int majorityElement(vector<int>& v) {
        int cnt=1,prev=v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]!=prev)cnt--;
            else cnt++;
            if(cnt<0){
                cnt=1;
                prev=v[i];
            }
            
        }
        return prev;
    }
};