typedef long long ll;

class Solution {
public:
    long long maxScore(vector<int>& v1, vector<int>& v2, int k) {
        int n = v1.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i += 1) idx[i] = i;
        sort(idx.begin(),idx.end(),[&](int i,int j) {
            return v2[i] > v2[j]; 
        });
        priority_queue<int,vector<int>,greater<int>> pq;
        ll s = 0, ans = 0;
        for(int i = 0; i < n; i += 1) {
            int j = idx[i];
            pq.push(v1[j]);
            s += v1[j];
            if(pq.size() > k) {
                s -= pq.top();
                pq.pop();
            }
            if(pq.size() == k)
                ans = max(ans,s * (ll)v2[j]);
        }
        return ans;
    }
};