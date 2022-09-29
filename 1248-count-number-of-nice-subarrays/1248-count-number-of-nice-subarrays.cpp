class Solution {
public:
    
    //Using Prefix sum
    int numberOfSubarrays(vector<int>& nums, int k){
      
        unordered_map<int, int> map;
        map[0]++;
        
        int sum = 0, ans = 0;
        
        for(auto num: nums){
            num = num%2;
            
            sum += num;
            map[sum]++;
            int reqd = sum-k;
            if(map.find(reqd) != map.end())
                ans += map[reqd];
        }
        
        return ans;
    }

};