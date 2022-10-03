class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
                
        int n = neededTime.size();
        
        if(n <= 1)
            return 0;
        
        int prev = 0, curr = 1;
        int ans = 0;
        
        for(; curr<n; prev++, curr++){
            if(colors[prev] == colors[curr]){
                ans += min(neededTime[prev], neededTime[curr]);
                neededTime[curr] = max(neededTime[prev], neededTime[curr]);
            }
        }
        
        return ans;
    }
};