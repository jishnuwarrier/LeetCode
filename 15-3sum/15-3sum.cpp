class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++){
            int l = i+1;
            int r = n-1;
            
            if(nums[i] > 0)
                break;
            
            while(l < r){
                if(nums[l]+nums[r] > -nums[i])
                    r--;
                else if(nums[l]+nums[r] < -nums[i])
                    l++;
                else{
                    vector<int> v = {nums[i], nums[l++], nums[r--]};
                    ans.push_back(v);
                    for(; l<r && nums[l]==v[1]; l++);
                    for(; l<r && nums[r]==v[2]; r--);
                }
            }
            for(; i+1<nums.size() && nums[i]==nums[i+1]; i++);
        }
        
        return ans;
    }
};