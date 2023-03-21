class Solution {
public:
    int minDeletion(vector<int>& v) {
        int cnt = 0,n = v.size();
        for(int i = 0; i < n - 1; i += 1) {
            if((i - cnt) % 2 == 0) {
                if(v[i] == v[i + 1]) cnt += 1;
            }
        }
        return cnt + ((n - cnt) & 1);
    }
};