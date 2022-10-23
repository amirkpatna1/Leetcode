class Solution {
public:
    vector<int> findErrorNums(vector<int>& v) {
        int n=v.size();
        int s=n*(n+1)/2;
        int ss = accumulate(v.begin(),v.end(),0);
        int sqs = n*(n+1LL)*(2*n+1LL)/6LL;
        long sqss = 0;
        for(int x:v)sqss+=x*x;
        int diff = s - ss;
        int sqdiff = sqs - sqss;
        int sum = sqdiff/diff;
        int miss = (diff + sum)/2;
        return {miss-diff,miss};
    }
};