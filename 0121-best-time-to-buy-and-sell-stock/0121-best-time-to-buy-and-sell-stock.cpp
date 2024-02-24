class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
        int buy=1e9,sell=-1e9;
        for(int i=0;i<v.size();i++){
            buy=min(buy,v[i]);
            sell=max(sell,v[i]-buy);
        }
        return sell;
    }
};