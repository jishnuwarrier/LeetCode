class Solution {
public:
    
    int n;
    vector<string> ans;
    
    void dfs(vector<string>& wordDict, string s, string str, int i){
        if(i == n){
            ans.push_back(str.substr(0, str.size()-1)); 
            return;
        }
        
        for(auto word:wordDict){
            if(i+word.size()<=n && s.substr(i, word.size()) == word){
                dfs(wordDict, s, str+word+" ", i+word.size());
            }
        }        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        n = s.size();
        
        for(auto word:wordDict){
            if(word.size()==n && s==word)
                ans.push_back(word);
    
            if(word.size()<n && s.substr(0, word.size()) == word){
                dfs(wordDict, s, word+" ", word.size());
            }
        }
        return ans;
    }
};