class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        queue<array<int, 2>> q;
        int fresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        
        int steps = 0;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(; !q.empty() && fresh>0; steps++){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [x, y] = q.front();
                q.pop();
                
                for(int j=0; j<4; j++){
                    int x1 = x+dir[j][0];
                    int y1 = y+dir[j][1];
                    
                    if(x1>=0 && x1<m && y1>=0 && y1<n && grid[x1][y1] == 1){
                        grid[x1][y1] = 2;
                        q.push({x1, y1});
                        fresh--;
                    }
                }
            }
        }
        
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return steps;
    }
};