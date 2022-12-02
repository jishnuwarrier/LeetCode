class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size()) return false;
        
        int n = word1.size();        
        vector<int> freq1(26, 0), freq2(26, 0), c1(26, 0), c2(26, 0);
        
        for(int i=0; i<n; i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
            
            c1[word1[i] - 'a'] = 1;
            c2[word2[i] - 'a'] = 1;
        }
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return (freq1==freq2 && c1==c2) ? true : false;
    }
};