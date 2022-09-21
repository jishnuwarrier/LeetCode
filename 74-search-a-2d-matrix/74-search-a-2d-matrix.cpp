class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        int frow = 0, lrow = matrix.size()-1, mid = frow;
        
        while(frow < lrow){
            mid = (frow+lrow)/2;
            
            if(frow == mid){
                if(!(matrix[mid][0]<=target && matrix[lrow][0]>target))
                    mid++;

                frow = lrow+1;
                continue;
            }
            
            if(matrix[mid][0] > target)
                lrow = mid;
            
            else if(matrix[mid][0] < target)
                frow = mid;
            
            else
                break;
            
        }
                
        int row = mid; mid = 0;
        int beg = 0, end = n-1;
        
        while(beg <= end){
            mid = (beg+end)/2;

            if(matrix[row][mid] < target)
                beg = mid+1;
            
            else if(matrix[row][mid] > target)
                end = mid-1;
            
            else 
                return true;
        }
        
        return false;
    }
};