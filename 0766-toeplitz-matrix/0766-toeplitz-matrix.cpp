class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int m=matrix.size(), n=matrix[0].size();
        
        for(int i=0; i<m; i++){
            int val = matrix[i][0];
            for(int x=i, y=0; x<m && y<n; x++,y++)
                if(matrix[x][y] != val)
                    return false;
        }
        
        for(int j=0; j<n; j++){
            int val = matrix[0][j];
            for(int x=0,y=j; x<m && y<n; x++, y++)
                if(matrix[x][y] != val)
                    return false;
        }
        
        return true;
    }
};