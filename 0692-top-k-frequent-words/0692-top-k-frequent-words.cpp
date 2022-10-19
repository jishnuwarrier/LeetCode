class Solution {
public:
    
    struct compare{
        bool operator()(const pair<string, int>&a, const pair<string, int>&b){ 
            return (a.second>b.second) || (a.second == b.second && a.first < b.first);
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> map;
        
        for(auto string: words)
            map[string]++;
        
        priority_queue<pair<string,int>, vector<pair<string,int>>, compare> pq;
        for(auto it: map){
            pq.push(it);
            
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end()); 
        return ans;
    }

};