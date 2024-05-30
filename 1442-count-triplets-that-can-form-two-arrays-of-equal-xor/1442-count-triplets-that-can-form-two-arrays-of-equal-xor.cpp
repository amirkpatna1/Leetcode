class Solution {
public:
    int countTriplets(vector<int>& v) {
        int ans = 0;
        v.insert(v.begin(), 0);
        for(int i = 1; i < v.size(); i += 1) {
            v[i] ^= v[i - 1];
        }
        // cout<<endl;
        
        for(int i = 0; i < v.size(); i += 1) {
            for(int j = i + 1; j < v.size(); j += 1) {
                if(v[i] == v[j]) ans += (j - i - 1);
            }
        }
        
        return ans;
    }
};