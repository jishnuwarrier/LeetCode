class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int gsum = accumulate(gas.begin(), gas.end(), 0);
        int csum = accumulate(cost.begin(), cost.end(), 0);
        
        if(gsum < csum)
            return -1;
        
        int pos = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum += gas[i]-cost[i];
            
            if(sum < 0){
                sum = 0;
                pos = i+1;
            }
        }
        
        return pos;
    }
};