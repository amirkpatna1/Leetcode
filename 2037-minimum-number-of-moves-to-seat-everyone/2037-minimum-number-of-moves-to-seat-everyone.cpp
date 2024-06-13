class Solution {
public:
    int minMovesToSeat(vector<int>& s, vector<int>& st) {
        sort(s.begin(),s.end());
        sort(st.begin(),st.end());
        int cnt=0;
        for(int i=0;i<s.size();i++){
            cnt+=abs(s[i]-st[i]);
        }
        return cnt;
    }
};