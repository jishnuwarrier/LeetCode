class Solution {
public:
vector<vector<int>> vis;
int m, n;
int bfs(vector<vector<int>>& grid, int k){
if(k>n+m-2)
return n+m-2;
vector<vector<int>> dir = {{0,1}, {0, -1}, {-1, 0}, {1, 0}};
queue<vector<int>> q;
q.push({0,0,k,0});
while(!q.empty()){
int size = q.size();
for(int temp=0; temp<size; temp++){
int x = q.front()[0], y=q.front()[1], newk = q.front()[2], steps = q.front()[3];
q.pop();
if(x==m-1 && y==n-1){
cout<<steps;
return steps;
}
if(x<0 || x==m || y==0 || y==n) continue;
if(vis[x][y]!=-1 && vis[x][y]>=newk)continue;
vis[x][y] = newk-grid[x][y];
for(int i=0; i<4; i++){
int x1 = x+dir[i][0], y1 = y+dir[i][1], z1 = newk-grid[x][y];
q.push({x1,y1,z1,steps+1});
}
}