class Solution {
public:
    vector<bool> dp;
    
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        dp = vector<bool>(n+1, false);
        
        for(auto word: wordDict){
            if(word.size()<n && dp[word.size()]==false && s.substr(0, word.size()) == word)
                dp[word.size()] = true;
            
            if(word.size()==n && word == s)
                return true;
        }
        
        for(int i=1; i<n; i++){
            if(dp[i] == false) continue;
            
            for(auto word: wordDict){
                if(i+word.size()<=n && s.substr(i, word.size()) == word)
                    dp[i+word.size()] = true;
                
                if(i+word.size()==n && word == s.substr(i, word.size()))
                    return true;
            }
        }
        return dp[s.size()];
    }
};