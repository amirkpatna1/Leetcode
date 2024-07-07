class Solution {
public:
    int passThePillow(int n, int time) 
    {

       int remtime = time % (2 * (n-1));



       if(remtime == 0) return 1;
       if(remtime <= n-1) return remtime + 1;
       else return n - (remtime - (n-1));

    }
};