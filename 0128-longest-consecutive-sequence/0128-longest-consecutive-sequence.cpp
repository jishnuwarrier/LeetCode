class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        vector<int> v;
        map<int, int> map;
        
        for(int i=0; i<nums.size(); i++)
            map[nums[i]]++;        
 
        int ans = 0;
        
        auto it = map.begin();
        auto it1 = it;
        
        for(; it!=map.end(); it = it1){
            int prev=it->first, currans = 1;
            it1 = it;
            for(it1++; it1!=map.end() && it1->first==prev+1; prev=it1->first, it1++, currans++);
            ans = max(ans, currans);
        }
        
        return ans;
    }
};