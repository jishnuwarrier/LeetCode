class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int l=0, r=n-1, mid;
        int smallest = INT_MAX;
        
        if(n == 1)
            return nums[0];
       
        while(l<=r){
            mid = (l+r)/2;
            
            if(nums[l]<=nums[mid] && nums[mid]<=nums[r])
                return nums[l];
            
            else if(nums[l]<=nums[mid] && nums[mid]>=nums[r])
                smallest = min(smallest, nums[r]),
                l=mid;
            
            else
                smallest = min(smallest, nums[mid]),
                r=mid;
            
            if((l+r)/2 == l)
                break;
        }
        return smallest;
    }
};