class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> ans;
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++){
            int l = i+1;
            int r = n-1;
            
            while(l < r){
                if(nums[l]+nums[r] > -nums[i])
                    r--;
                else if(nums[l]+nums[r] < -nums[i])
                    l++;
                else
                    ans.insert({nums[i],nums[l++],nums[r--]});
            }
        }
        
        res = vector<vector<int>>(ans.begin(), ans.end());        
        return res;
    }
};