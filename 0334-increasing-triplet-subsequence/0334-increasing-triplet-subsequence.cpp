class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pre(n, INT_MAX);
        vector<int> post(n, INT_MIN);
        
        for(int i=1; i<n; i++){
            pre[i] = min(pre[i-1], nums[i-1]);
            post[n-i-1] = max(post[n-i], nums[n-i]);
        }
        
        for(int i=1; i<n-1; i++)
            if(pre[i] < nums[i] && nums[i] < post[i])
                return true;
            
        return false;
    }
};