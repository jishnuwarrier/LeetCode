class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_map<int, int> map;
        
        for(auto num: nums)
            if(num > 0)
                map[num] = 1;
        
        for(int x=1; x<=1e5; x++)
            if(map.find(x) == map.end())
                return x;
            
        return 1e5+1;
    }
};