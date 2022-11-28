class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int, pair<int, int>> map;
        vector<vector<int>> ans {{},{}};
        
        for(auto match: matches){
            map[match[0]].first++;
            map[match[1]].second++;
        }
        
        for(auto it: map){
            if(it.second.second == 0)
                ans[0].push_back(it.first);
            
            if(it.second.second == 1)
                ans[1].push_back(it.first);
        }

        return ans;
    }
};