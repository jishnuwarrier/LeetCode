class Solution {
public:
    int ans = 0;
    
    void dfs(vector<string>&nums, set<int>s, int i, int length){
        
        ans = max(ans, length);
        if(i == nums.size())
            return;
 
        dfs(nums, s, i+1, length);
        
        bool unique  = true;
        for(int j=0; j<nums[i].size(); j++){
            if(s.find(nums[i][j]) == s.end())
                s.insert(nums[i][j]);
            else
                unique = false;
        }

        if(unique == false)
            return;
        
        dfs(nums, s, i+1, length+nums[i].size());
    }
    
    
    int maxLength(vector<string>& nums) {
         
        set<int> s;
        dfs(nums, s, 0, 0);
        return ans;
    }
};
