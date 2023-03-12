//I have to maximise (s1+s2+s3+...+sk) * min(e1,e2,..,ek)
//we can sort the array according to efficiency , why ? as we need to select minimum efficiency among all
//if we sort then it will be easier for us to get min eff
//Now iterate from 0 to n and put each numbers in min heap (so that min speed will be at the top and you can remove this if you find better speed)
//add to the sum while adding and each time take max(s*e)
//remove once your pq have more than k elements


class Solution {
private:
    int mod = (int)1e9 + 7;
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<int> idx(n);
        for(int i = 0; i < n; i += 1){
            idx[i] = i;
        }
        sort(idx.begin(),idx.end(),[&](int i,int j){
            return efficiency[i] > efficiency[j];
        });
        priority_queue<int,vector<int>,greater<int>> pq;
        long long ans = 0;
        long long s = 0;
        for(int i = 0; i < n; i += 1) {
            pq.push(speed[idx[i]]);
            s = s + speed[idx[i]];
            if(pq.size() > k) {
                s = s - pq.top();
                pq.pop();
            }
            ans = max(ans,s * efficiency[idx[i]]);
        }
        return ans%mod;
    }
};