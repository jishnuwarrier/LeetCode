class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        unordered_map<char, int> pmap;
        unordered_map<char, int> smap;
        
        int m = s.size(), n = p.size();
        
        for(int i=0; i<n; i++){
            pmap[p[i]]++;
            smap[s[i]]++;
        }
        
        for(int i=0; i<=m-n; i++){
            
            if(pmap == smap) ans.push_back(i);
            
            smap[s[i]]--;
            smap[s[i+n]]++;
            
            if(smap[s[i]] == 0) smap.erase(s[i]);
        }
        
        return ans;
    }
};