class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // [-8,-7,-1,0,5]
        int ans = 0, currLikeTimeCoeff = 0, prevLikeTimeCoeff = 0;
        vector<int> ps(n + 1);
        for(int i = 1; i <= n; i += 1) {
            ps[i] = ps[i - 1] + satisfaction[i - 1];
            currLikeTimeCoeff += (satisfaction[i - 1] * i);
        }
        // cout<<currLikeTimeCoeff<<endl;
        // for(int x : ps) cout<<x<<" ";
        // cout<<endl;
        ans = max(currLikeTimeCoeff,ans);
        for(int i = 1; i <= n; i += 1) {
            currLikeTimeCoeff -= (ps.back() - ps[i - 1]);
            // cout<<(ps[i] - ps[i - 1])<<" "<<currLikeTimeCoeff<<endl;
            ans = max(ans,currLikeTimeCoeff);
        }
        
        return ans;
        
    }
};