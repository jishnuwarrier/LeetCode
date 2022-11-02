class Solution {
public:
    string s,p;
    int m,n;
    vector<vector<int>>dp;
    
    int dfs(int i, int j){

        if(i>=m && j>=n) return 1;
        if(j>=n) return -1;
        
        if(i>=m){
            for(; j<n && p[j]=='*'; j++);
            return (j<n) ? -1 : 1;   
        }
        
        if(dp[i][j] != 0) return dp[i][j];
        bool check = (s[i] == p[j] || p[j]=='?');
        
        if(p[j]=='*')
            return dp[i][j] = max(dfs(i,j+1), max(dfs(i+1,j), dfs(i+1,j+1)));
        
        else if(check)
            return dp[i][j] = dfs(i+1, j+1);
        
        return -1;
    }
    
    bool isMatch(string s1, string s2) {
        s=s1, p=s2;
        m=s.size(), n=p.size();
        dp = vector<vector<int>>(m, vector<int>(n,0));
        return (dfs(0, 0) == -1) ? false : true;
    }
};