//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
// //{{1,2,3}
//     ^
// //,{4,5,6}
//     ^
// //,{7,8,9}}
//     ^
//     push 1 in ans --> and increase its index
// //{{1,2,3}
//       ^
// //,{4,5,6}
//     ^
// //,{7,8,9}}
//     ^
// push 2 in ans --> and increase its index

// //{{1,2,3}
//         ^
// //,{4,5,6}
//     ^
// //,{7,8,9}}
//     ^
// push 3 in ans --> and increase its index

// //,{4,5,6}
//     ^
// //,{7,8,9}}
//     ^
// [1,2,3,3,4,5,5,6,7] 

// [1,5,7]
//       ^
// [2,3,6]
//       ^
// [3,4,5]
//       ^

    


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i = 0; i < arr.size(); i += 1) {
            if(!arr[i].empty()) {
                pq.push({arr[i][0],i,0});
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            vector<int> mn = pq.top();pq.pop();
            int val = mn[0];
            int i = mn[1];
            int j = mn[2];
            ans.push_back(val);
            if(j < arr[i].size() - 1) {
                pq.push({arr[i][j + 1],i,j + 1});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends