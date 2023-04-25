class SmallestInfiniteSet {
public:
    vector<bool> v;
    int i=0;
    SmallestInfiniteSet() {
        v.resize(1000);
        for(int i=0;i<1000;i++)v[i]=true;
    }
    
    int popSmallest() {
        while(!v[i])i++;
        // cout<<i<<" ";
        v[i++]=false;
        return i;
    }
    
    void addBack(int num) {
        v[num-1]=true;
        if(num-1<i)i=num-1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */