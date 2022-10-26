class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int s=v[0],ss=v[0];
        for(int i=1;i<v.size();i++){
            s+=v[i];
            int rem=s%k;
            if(rem==0 || mp.count(rem))return true;
            mp[ss%k]++;
            ss=s;
        }
        return false;
    }
};