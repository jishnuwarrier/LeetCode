class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(map[key].size() == 0)
            return "";
        
        int l = 0, r = map[key].size(), mid;
        string ans;
        
        while(l<r){
            mid = (l+r)/2;
            if(map[key][mid].first == timestamp)
                return map[key][mid].second;
            
            if(map[key][mid].first > timestamp)
                r=mid;
            
            else{
                ans = map[key][mid].second;
                l=mid+1;
            }
        }
        
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */