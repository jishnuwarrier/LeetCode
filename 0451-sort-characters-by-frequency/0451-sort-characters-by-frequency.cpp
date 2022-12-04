class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        priority_queue<pair<int,char>> pq;
        
        for(auto ch: s)
            map[ch]++;
        
        
        for(auto it: map)
            pq.push({it.second, it.first});
        
        string ans;
        
        while(pq.size()>0){
            auto it = pq.top();
            pq.pop();
            for(int i=0; i<it.first; i++){
                ans += it.second;
            }
        }
        
        return ans;
    }
};