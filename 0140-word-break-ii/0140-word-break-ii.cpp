class Solution {
public:  
    void dfs(vector<string> &ans, vector<string>& wordDict, string s, string sentence, int i){
        if(i == s.size())
            ans.push_back(sentence.substr(0, sentence.size()-1)); 
        
        else
            for(auto word:wordDict)
                if(i+word.size()<=s.size() && s.substr(i, word.size()) == word)
                    dfs(ans, wordDict, s, sentence+word+" ", i+word.size());
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        dfs(ans, wordDict, s, "", 0);
        return ans;
    }
};