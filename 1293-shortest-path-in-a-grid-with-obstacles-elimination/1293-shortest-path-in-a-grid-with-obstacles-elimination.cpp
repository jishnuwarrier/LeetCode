class Solution {
public:

    int shortestPath(vector<vector<int>>& grid, int k) {
        
        vector<vector<int>> dir = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        queue<vector<int>> q;
        q.push({0,0,k});
        int step = 0;
        
        for(; !q.empty(); step++){
            int size = q.size();
            while(size-- > 0){
                int x = q.front()[0];
                int y=q.front()[1];
                int newk = q.front()[2];
                q.pop();
                 
                if(x==m-1 && y==n-1) return step;
                if(x<0 || x>=m || y<0 || y>=n) continue;
                if(vis[x][y]!=-1 && vis[x][y]>=newk)continue;
            
                
                if(grid[x][y]==1){
                    if(newk > 0) newk--;
                    else continue;
                }
                vis[x][y] = newk;
                
                for(int i=0; i<4; i++){
                    int x1 = x+dir[i][0], y1 = y+dir[i][1];
                    q.push({x1,y1,newk});
                }                 
            }
        }
        return (-1);
    }
};