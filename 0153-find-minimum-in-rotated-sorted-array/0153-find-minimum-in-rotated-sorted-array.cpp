class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=n-1, mid;
        
        while(l<=r){
            mid = (l+r)/2;
            if(nums[l]<nums[r]) return nums[l];
            else if(nums[l]<=nums[mid] && nums[mid]>=nums[r]) l=mid+1;
            else r=mid;
        }
        return nums[mid];
    }
};