class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int> s;
        for(auto num: nums)
            s.insert(num);
        
        nums = vector<int>(s.begin(), s.end());
        return s.size();        
    }
};