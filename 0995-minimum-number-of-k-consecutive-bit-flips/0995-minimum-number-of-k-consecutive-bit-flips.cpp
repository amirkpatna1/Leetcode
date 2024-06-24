class Solution {
public:
    int minKBitFlips(vector<int>& v, int k) {
        int flip=0,res=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==flip%2){
                if(i+k>v.size())return -1;
                res++,flip++;
                v[i]-=2;
            }
            if(i>=k-1 && v[i-k+1]<0)flip--,v[i-k+1]+=2;
        }
        return res;
    }
};