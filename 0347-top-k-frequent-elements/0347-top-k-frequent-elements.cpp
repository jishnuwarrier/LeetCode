class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> map;
        priority_queue<int> pq;
        
        for(auto num: nums)
            freq[num]++;
        
        for(auto it: freq){
            map[it.second].push_back(it.first);
            pq.push(it.second);
        }
        
        for(int i=0; i<k; i++){
            ans.push_back(map[pq.top()][map[pq.top()].size()-1]);
            map[pq.top()].pop_back();
            pq.pop();
        }
        
        return ans;
    }
};