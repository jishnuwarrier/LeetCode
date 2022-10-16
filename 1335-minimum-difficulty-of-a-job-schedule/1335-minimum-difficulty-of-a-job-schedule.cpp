class Solution {
public:
    vector<vector<int>>dp;
    
    int solve(int idx, vector<int>&job, int d){
        
        if(idx == job.size()){
            if(d == 0)    
                return 0;        
            return 1e9 ;
        }  
        
        if(d <= 0)
            return 1e9;
        
        if(dp[idx][d] != -1)
            return dp[idx][d];
        
        int ans = INT_MAX, maxi = INT_MIN;
        
        for(int i=idx; i<job.size(); i++){
            maxi = max(maxi, job[i]);
            int temp=maxi+solve(i+1, job, d-1);
            ans = min(temp, ans);
        }
        dp[idx][d] = ans;
        return ans;
    }
    
    
    int minDifficulty(vector<int>&job, int d) {
	
        int n = job.size();
        dp = vector<vector<int>>(n+1, vector<int>(d+1, -1));
        int ans = solve(0, job, d);
        
        if(ans >= 1e9)    
            return -1;
        
        return ans;
    }
};