class Solution {
public:
    string createstring(vector<string>&word){
        string ans;
        for(auto str: word)
            ans += str;
        
        return ans;
    }
    
    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        return (createstring(word1) == createstring(word2));
    }
};