class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> map;
        
    for(auto str: strs){
        string s = str;
        sort(s.begin(), s.end());
        map[s].push_back(str);
    }
        
    for(auto it: map){
        vector<string> v;
        for(auto str: it.second)
            v.push_back(str);
        ans.push_back(v);
    }
        
    return ans;
        
    }
};