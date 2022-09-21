class Solution {
public:
           
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        
        for(auto str: strs){
            vector<int> freq_arr(26, 0);
            
            string hash;
            
            for(auto ch: str){
                freq_arr[ch-'a']++;
            }
            
            for(auto freq: freq_arr){
                hash.append(to_string(freq)+" ");
            }
            map[hash].push_back(str);
        }
        
        vector<vector<string>> ans;
        
        for(auto it: map){
            vector<string> v;
            for(auto str: it.second)
                v.push_back(str);
            ans.push_back(v);
        }
        
        return ans;
    }
};