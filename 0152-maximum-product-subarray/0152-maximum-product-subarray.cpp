class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = INT_MIN;
        int n = nums.size();
        int curmax = 1, curmin = 1;
        
        int i=0, j=0;
        for(auto num: nums){
            
            if(num == 0){
                ans = max(ans, 0);
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