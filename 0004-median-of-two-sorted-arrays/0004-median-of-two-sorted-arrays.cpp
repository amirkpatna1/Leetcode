class Solution {
public:
    
    
    
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        if(n > m) return findMedianSortedArrays(arr2,arr1);
        int low = 0, high = n;
        bool flag = (n + m) & 1;
        while(low<=high)
        {
            int cut1=low+(high-low)/2;
            int cut2=(m + n + 1)/2 - cut1;
            
            int left1 = cut1==0 ? INT_MIN : arr1[cut1-1];
            int left2 = cut2==0 ? INT_MIN : arr2[cut2-1];
            int right1 = cut1==n ? INT_MAX : arr1[cut1];
            int right2 = cut2==m ? INT_MAX : arr2[cut2];
            
            if(left1<=right2 && left2<=right1)
            {
                return flag ? max(left1,left2) : (max(left1,left2) + min(right1,right2)) * 0.5;
            }
            else if(left1>right2)
            {
                high=cut1-1;
            }
            else
            {
                low=cut1+1;
            }
        }
        return 0;
    }
};