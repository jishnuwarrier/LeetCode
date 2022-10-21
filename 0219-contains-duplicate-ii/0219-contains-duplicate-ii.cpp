class Solution {
public:
    bool containsNearbyDuplicate(vector<int>&nums, int k) {
        
        if(k == 0)
            return false;
        
        int m = nums.size();        
        unordered_map<int, int> map;
        
        for(int i=0; i<m; i++){
            if(map.find(nums[i]) != map.end() && i-map[nums[i]]<= k)
                return true;
            
            map[nums[i]] = i;
        }
        
        return false;
    }
};