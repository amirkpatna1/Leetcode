class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& v) {
        this->k=k;
        for(int i=0;i<v.size();i++)pq.push(v[i]);
        while(pq.size()>this->k){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k)pq.pop();
        // for(int &x:v)cout<<x<<" ";
        // cout<<endl;
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */