typedef long long ll;
class Solution {
public:
    
    bool helper(int k,int index,int maxSum,int n) {
        ll val = (ll)(k  + index) * (n - index - 1LL) - ((n - index)*(n - index - 1))/2LL + k*(index + 1LL) + (index*(index + 1LL))/2LL;
        cout<<val<<" "<<k<<endl;
        return val <= maxSum;
    }
    
    int maxValue(int n, int i, int maxSum) {
        int l = 0, r = maxSum, j = n - i - 1;
        while (l < r) {
            long m = (l + r + 1) / 2;
            auto need = m * m - ((m > i ? (m - i - 1) * (m - i) : 0)
                + (m > j ? (m - j - 1) * (m - j) : 0)) / 2;
            if (need <= maxSum - n)
                l = m;
            else
                r = m - 1;
        }
        return l + 1;
    }
};