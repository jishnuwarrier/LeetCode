class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = (long)*max_element(nums.begin(), nums.end());
        int n = nums.size();
        int curmax = 1, curmin = 1;
        
        int i=0, j=0;
        for(auto num: nums){
            
            if(num == 0){
                curmax = curmin = 1;
                continue;
            }
            
            int temp = curmax*num;
            curmax = max(max(temp, curmin*num), num);
            curmin = min(min(temp, curmin*num), num);
            
            ans = max(ans, curmax);
        }
        
        return ans;
    }
};