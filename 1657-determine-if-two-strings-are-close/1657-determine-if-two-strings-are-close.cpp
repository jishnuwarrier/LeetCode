class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size()) return false;
        
        int n = word1.size();
        
        set<char> s1, s2;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        
        for(int i=0; i<n; i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
            
            s1.insert(word1[i]); s2.insert(word2[i]);
        }
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return (freq1==freq2 && s1==s2) ? true : false;
    }
};