class Solution {
public:
        
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> ans;
        
        for(int k=0; k<n; k++){
            int i=0, j=k;
           
            while(i>=0 && i<m && j>=0 && j<n){
                if(grid[i][j] == 1){
                    if(j==n-1 || grid[i][j+1] == -1){
                        ans.push_back(-1);
                        i=m;
                    }
                    
                    else
                        i++, j++;
                    
                    continue;
                }
                
                else{
                    if(j==0 || grid[i][j-1] == 1){
                        ans.push_back(-1);
                        i=m;
                    }
                    
                    else
                        i++, j--;
                }
            }
            
            if((j<0 || j==n) && ans.size()<=k)
                ans.push_back(-1);
            
            else if(i==m && ans.size()<=k)
                ans.push_back(j);
            
        }
        
        return ans;
    }
};