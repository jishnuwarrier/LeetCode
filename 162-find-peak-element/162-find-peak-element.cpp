class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0, r = n-1;
        
        while(l <= r){
            int mid = (l+r)/2;
            
            if(l == r)
                return l;
            
            if(mid == 0){
                if(nums[0] > nums[1])
                    return 0;
                else
                    return 1;
            }
            
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            
            else if(nums[mid] < nums[mid-1])
                r = mid-1;
            
            else
                l = mid+1;
        }
        
        return INT_MIN;
    }
};