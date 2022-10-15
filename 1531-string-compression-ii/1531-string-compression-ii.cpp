class Solution {
public:
    vector<vector<vector<vector<int>>>> dp;
        
    int recurse(string &s, int ind, char prev, int prevfreq, int k){
    
        if(k<0)
            return INT_MAX;
        
        if(ind == s.size())
            return 0;
        
        if(prevfreq >= 10)
            prevfreq = 10;
        
        if(dp[ind][prev-'a'][prevfreq][k] != -1)
            return dp[ind][prev-'a'][prevfreq][k];
        
        int ans = min(INT_MAX, recurse(s, ind+1, prev, prevfreq, k-1));
        
        if(s[ind] == prev){
            if(prevfreq <= 1 || prevfreq == 9)
                ans = min(ans, 1+recurse(s, ind+1, prev, prevfreq+1, k));
            else
                ans = min(ans, recurse(s, ind+1, prev, prevfreq+1, k));
        }
        
        else
            ans = min(ans, 1+recurse(s, ind+1, s[ind], 1, k));
        
        return dp[ind][prev-'a'][prevfreq][k] = ans;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        
        int n = s.size(); 
        
        bool check = true;
        for(int i=1; i<n; i++){
            if(s[i] != s[i-1])
                check = false;
        }
        
        if(check == true){
            if(n-k == 100) return 4;
            if(n-k >= 10) return 3;
            if(n-k > 1) return 2;
            if(n-k == 1) return 1;
            
            return 0;
        }
        
        dp = vector<vector<vector<vector<int>>>>(n+1, vector<vector<vector<int>>>(26, vector<vector<int>>(11, vector<int>(k+1, -1))));  
        
        return recurse(s, 0, 'a', 0, k);
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);