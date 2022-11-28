class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_set<int> losers;
        unordered_set<int> winners;
        unordered_set<int> oneloss;
        
        for(auto match: matches){
                        
            if(winners.find(match[0]) == winners.end() && losers.find(match[0]) == losers.end() && oneloss.find(match[0]) == oneloss.end())
                winners.insert(match[0]);
            
            if(winners.find(match[1]) != winners.end())
                winners.erase(match[1]);
            
            if(oneloss.find(match[1]) != oneloss.end()){
                oneloss.erase(oneloss.find(match[1]));
                losers.insert(match[1]);
            }            
            
            if(oneloss.find(match[1]) == oneloss.end() && losers.find(match[1]) == losers.end())
                oneloss.insert(match[1]);
        }
    
        vector<vector<int>> ans;
        ans.push_back(vector<int> (winners.begin(), winners.end()));
        ans.push_back(vector<int> (oneloss.begin(), oneloss.end()));
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};