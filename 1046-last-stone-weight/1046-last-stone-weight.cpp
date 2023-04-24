class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int> pq(v.begin(),v.end());
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a==b)continue;
            pq.push(a-b);
        }
        return pq.empty()?0:pq.top();
    }
};