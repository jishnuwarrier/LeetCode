class Solution {
public:

    struct triplet{
        int x,y,z;
    };
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        vector<vector<int>> dir = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        int m=grid.size(), n=grid[0].size();
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n, vector<bool>(k+1)));
        queue<triplet> q;
        q.push({0,0,k});
        int step = 0;
        
        for(; !q.empty(); step++){
            int size = q.size();
            while(size-- > 0){
                auto [x,y,z] = q.front();
                q.pop();
                
                if(x<0||x==m||y<0||y==n||z<0||vis[x][y][z]) continue;
                if(x==m-1 && y==n-1) return step;
                
                vis[x][y][z]=true;
                
                for(int i=0; i<4; i++){
                    int x1=x+dir[i][0], y1=y+dir[i][1];
                    q.push({x1, y1, z-grid[x][y]});
                }
                
            }
        }
        return (-1);
    }
};