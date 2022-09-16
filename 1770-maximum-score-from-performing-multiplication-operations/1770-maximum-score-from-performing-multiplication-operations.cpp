class Solution {
public:
    
    vector<vector<int>> dp;
    int recurse(vector<int> &nums, vector<int>& multipliers, int i, int l){
        
        int n = nums.size();
        if(i == multipliers.size())
            return 0;
        
        if(dp[i][l] != INT_MIN)
            return dp[i][l];
        
        int beg = nums[l]*multipliers[i] + recurse(nums, multipliers, i+1, l+1);
        int end = nums[n-(i-l)-1]*multipliers[i] + recurse(nums, multipliers, i+1, l);

        return dp[i][l] = max(beg,end);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        dp.resize(multipliers.size()+1,vector<int>(multipliers.size()+1,INT_MIN));
        return recurse(nums, multipliers, 0, 0);
    }
};