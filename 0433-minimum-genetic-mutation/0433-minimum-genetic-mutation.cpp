class Solution {
public:
    int ans = INT_MAX;
    unordered_map<string, vector<string>>map;
    
    bool dist(string s1, string s2){
        int count = 0;
        for(int i=0; i<8; i++)
            if(s1[i] != s2[i])
                count++;
        
        return (count == 1) ? true : false;
    }
    
    void dfs(string &gene, string &end, int steps){
        if(steps > 10)
            return;
        
        if(gene == end)
            ans = min(ans, steps);
        
        for(auto str: map[gene]){
            dfs(str, end, steps+1);
        }
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        
        for(auto str: bank)
            if(dist(start, str))
                map[start].push_back(str);
        
        for(int i=0; i<bank.size(); i++){
            for(int j=i+1; j<bank.size(); j++){
                
                if(i==j) continue;
                
                if(dist(bank[i], bank[j]))
                    map[bank[i]].push_back(bank[j]),
                    map[bank[j]].push_back(bank[i]);
            }   
        }
        
        dfs(start, end, 0);
        return (ans == INT_MAX) ? -1 : ans;
    }
};