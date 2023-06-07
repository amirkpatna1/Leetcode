//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:


    void func(vector<int> &ans,int &currSum,vector<int> &v,int i) {
        if(i >= v.size()) {
            
            return ;
        }
        for(int j = i; j < v.size(); j += 1) {
            currSum += v[j];
            ans.push_back(currSum);
            func(ans,currSum,v,j + 1);
            currSum -= v[j];
        }
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        int currSum = 0;
        ans.push_back(currSum);
        func(ans,currSum,arr,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends