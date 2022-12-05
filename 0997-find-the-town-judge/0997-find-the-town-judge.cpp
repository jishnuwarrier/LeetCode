class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> adj[n];
        
        vector<int> freq(n, 0);
        
        for(auto v: trust){
            adj[v[0]-1].push_back(v[1]-1);
            freq[v[1]-1]++;
        }

        for(int i=0; i<n; i++){
            if(freq[i]==n-1 && adj[i].size()==0)
                return i+1;
        }
        
        return -1;
    }
};