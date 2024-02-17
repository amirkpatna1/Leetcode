class Solution {
public:
    int furthestBuilding(vector<int>& v, int b, int l) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<v.size()-1;i++){
            int d=v[i+1]-v[i];
            if(d>0)pq.push(d);
            if(pq.size()>l){
                if(pq.top()>b)return i;
                b-=pq.top();
                pq.pop();
            }
        }
        return v.size()-1;
    }
};