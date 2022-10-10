class Solution {
public:
    
    vector<vector<int>> dp;
    
    int dfs(vector<vector<int>>& matrix, int val, int i, int j){
        
        if(i<0 || j<0 || i==matrix.size() || j==matrix[0].size() || matrix[i][j] <= val)
            return 0;
        
        if(dp[i][j] != 0)
            return dp[i][j];
        
        val = matrix[i][j];
        matrix[i][j] = -1;
        
        int maxdist = max(max(dfs(matrix, val, i-1, j), dfs(matrix, val, i+1, j)), max(dfs(matrix, val, i, j-1), dfs(matrix, val, i, j+1)));
        
        matrix[i][j] = val;
        
        dp[i][j] = 1+maxdist;
        return 1+maxdist;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                int maxdist = max(max(dfs(matrix, matrix[i][j], i-1, j), dfs(matrix, matrix[i][j], i+1, j)), max(dfs(matrix, matrix[i][j], i, j-1), dfs(matrix, matrix[i][j], i, j+1)));
                
                dp[i][j] = 1+maxdist;
                
                ans = max(ans, 1+maxdist);
            }
        }
        
        return ans;
    }
};