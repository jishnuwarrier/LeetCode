class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>>dp;
    
    int rollDice(int d, int f, int target){
        if(d==0 || target<=0) 
            return (int)(d==target);
        
        if(dp[d][target]!=-1) 
            return dp[d][target];
        
        int res = 0;
        for(int i=1;i<=f;i++)
            res =  (res + rollDice(d-1,f,target-i))%mod;                
    
        dp[d][target] = res;
        return dp[d][target];
    }
    
    int numRollsToTarget(int d, int f, int target) {
        dp = vector<vector<int>>(d+1,vector<int>(target+1,-1));
        return rollDice(d,f,target);
    }
};