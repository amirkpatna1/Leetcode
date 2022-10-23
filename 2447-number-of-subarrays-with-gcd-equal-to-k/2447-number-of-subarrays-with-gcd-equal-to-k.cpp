class Solution {
public:
    int subarrayGCD(vector<int>& v, int k) {
		int cnt = 0,n=v.size();
        for (int i = 0; i < n; i++){
            int currGcd = 0;
            for (int j = i; j < n; j++){
                currGcd = gcd(currGcd, v[j]);
                if (currGcd == k) cnt++;
            }
        }
        return cnt;
    }
};