class Solution {
public:
    int minOperations(vector<string>& logs) {
        int requiredOperation = 0;
        for(int i = 0; i < logs.size(); i++){
            if(logs[i] == "../"){
                if(requiredOperation != 0) 
                    requiredOperation--;
            }
            else{
                if(logs[i] != "./")
                    requiredOperation++;
            }
        }
        return requiredOperation;
    }
};