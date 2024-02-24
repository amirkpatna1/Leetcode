class Solution {
public:
    
    int findParent(vector<int> &parent, int i) {
        if(i == parent[i]) return i;
        return findParent(parent, parent[i]);
    }
    
    
    
    
    vector<int> findAllPeople(int n, vector<vector<int>>& v, int f) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        p[f] = 0;
        sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });
        vector<int> temp;
        int time = v[0][2];
        for(int i = 0; i < v.size(); i += 1) {
            if(time != v[i][2]) {
                for(int x : temp) {
                    int a = findParent(p, x);
                    if(a != 0) {
                        p[x] = x;
                    }
                }
                temp.clear();
                time = v[i][2];
            }
            temp.push_back(v[i][0]);
            temp.push_back(v[i][1]);
            int a = findParent(p, v[i][0]);
            int b = findParent(p, v[i][1]);
            if(a == 0) {
                p[b] = a;
            } else {
                p[a] = b;
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i += 1) {
            int a = findParent(p, i);
            if(a == 0) ans.push_back(i);
        } 
        return ans;
        
    }
    
    
    
};