class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int rep;
        vector<bool> check(nums.size(), false);
        
        for(int i=0; i<nums.size(); i++){
            if(check[nums[i]-1] == false)
                check[nums[i]-1] = true;
            
            else
                rep = nums[i];
            
        }
        
        for(int i=0; i<check.size(); i++){
            if(check[i] == false)
                return {rep, i+1};
        }
        
        return {};
    }
};