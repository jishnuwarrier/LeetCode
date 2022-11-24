class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans = 0;
        map<int, int> map;
        vector<int> prefix (nums.size()+1, 0);
        map[0] = 1;
        
        for(int i=1; i<=nums.size(); i++){
            prefix[i] = prefix[i-1] + nums[i-1];
            ans += (map[prefix[i] - k]);
            map[prefix[i]]++;
        }
        
        return ans;
    }
};