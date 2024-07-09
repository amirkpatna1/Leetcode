class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitingTime=customers[0][1];
        int end=customers[0][1]+customers[0][0];
        for(int i=1;i<customers.size();i++){
            int arrive=customers[i][0];
            int start=max(arrive,end);
            end=start+customers[i][1];
            waitingTime+=end-arrive;
        }
        
        return waitingTime/customers.size();

    }
};