class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int m = word1.size(), n = word2.size();
        
        int i=0, j=0;
        for(int x=0, y=0; i<m && j<n;){
            while(x<word1[i].size() && y<word2[j].size()){
                if(word1[i][x++] != word2[j][y++])
                    return false;
            }
            if(x == word1[i].size())
                x=0, i++;
            
            if(y == word2[j].size())
                y=0, j++;
        }
        
        if(i!=m || j!=n)
            return false;
        
        return true;
    }
};