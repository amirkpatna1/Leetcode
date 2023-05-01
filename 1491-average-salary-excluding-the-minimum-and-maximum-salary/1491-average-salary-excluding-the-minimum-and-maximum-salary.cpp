class Solution {
public:
    double average(vector<int>& v) {
        return (accumulate(v.begin(),v.end(),0) - *max_element(v.begin(),v.end()) - *min_element(v.begin(),v.end()))/(double)(v.size() - 2);
    }
};