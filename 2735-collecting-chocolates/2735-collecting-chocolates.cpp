class Solution {
public:
    long long minCost(vector<int>& v, int x) {
        int n = v.size();
        vector<int> A(n,INT_MAX);
        long long ans = LONG_MAX;
        for(int i = 0; i < n; i += 1) {
            long long s = 0;
            for(int j = 0; j < n; j += 1) {
                A[j] = min(A[j],v[(i + j) % n]);
                s += A[j];
            }
            s += (long long)i * (long long)x;
            ans = min(ans,s);
        }
        return ans;
    }
};