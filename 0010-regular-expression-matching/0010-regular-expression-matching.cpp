class Solution {
public:
    int m, n;
    string s,p;
    vector<vector<int>> dp;
    
    int dfs(int i, int j){

        if(i>=m && j>=n) return 1;
        if(j>=n) return -1;
        
        if(i>=m){
            while(j<n-1 && p[j+1]=='*')
                j+=2;
            
            return (j<n)? -1 : 1;
        }
        
        if(dp[i][j] != 0) return dp[i][j];
        
        bool check = (s[i]==p[j] || p[j]=='.');
          
        if(j<n-1 && p[j+1]=='*'){
            if(check)
                return dp[i][j] = (max(dfs(i+1,j), dfs(i,j+2)));
            else
                return dp[i][j] = dfs(i,j+2);
        }
        
        else if(check  == true)
            return dp[i][j] = dfs(i+1, j+1);
        
        return -1;
    }
    
    bool isMatch(string s1, string s2) {
        s=s1, p=s2;
        m=s.size(), n=p.size();
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        return (dfs(0, 0) == -1) ? false : true;
    }
};