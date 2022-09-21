class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();

        int beg = 0, end = m*n-1, mid = 0;
        
        while(beg <= end){
            mid = (beg+end)/2;
            
            int i = mid/n, j = mid%n;
            
            if(matrix[i][j] < target)
                beg = mid+1;
                
            else if(matrix[i][j] > target)
                end = mid-1;
                
            else
                return true;
        }
        
        return false;
    }
};