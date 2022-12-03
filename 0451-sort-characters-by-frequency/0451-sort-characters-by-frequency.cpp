struct comp {
    template <typename T>
  
    bool operator()(const T& l, const T& r) const {
        return (l.second != r.second) ? l.second > r.second : l.first < r.first;
    }
};

class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char, int> map;
        vector<pair<char, int>> v;
        
        for(auto ch: s)
            map[ch]++;
        
        set<pair<char, int>, comp> set(map.begin(), map.end());
        string ans;
        
        for(auto it: set){
            for(int i=0; i<it.second; i++){
                ans += it.first;
            }
        }
        
        return ans;
    }
};