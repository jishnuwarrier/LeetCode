class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(grid[i][j] == '0' || grid[i][j] == '2')
            return;
        
        grid[i][j] = '2';
        
        if(i>0)
            dfs(grid, i-1, j);
        if(i<grid.size()-1)
            dfs(grid, i+1, j);
        if(j>0)
            dfs(grid, i, j-1);
        if(j<grid[0].size()-1)
            dfs(grid, i, j+1);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                 if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ans++;
                 }
            }
        }

        return ans;
    }
};