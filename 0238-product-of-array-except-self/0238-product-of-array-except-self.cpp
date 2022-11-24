class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> suffix(nums.size());
        vector<int> ans(nums.size());
        
        ans[0] = 1; suffix[nums.size()-1] = 1;
        
        for(int i=1; i<nums.size(); i++)
            ans[i] = ans[i-1] * nums[i-1];
        
        for(int i=nums.size()-2; i>=0; i--)
            suffix[i] = suffix[i+1] * nums[i+1];
        
        for(int i=0; i<nums.size(); i++)
            ans[i] *= suffix[i];
            
        return ans;
    }
};