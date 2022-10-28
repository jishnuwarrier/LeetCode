class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> map;
        
    for(auto const &str: strs){
        string s = str;
        sort(s.begin(), s.end());
        map[s].push_back(str);
    }
    
    ans.reserve(map.size());
    for(auto it: map)
        ans.push_back(move(it.second));
        
    return ans;
        
    }
};