class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        string rev;
        
        for(int i=n-1; i>=0; ){
            int j;
            for(; i>=0 && s[i] == ' '; i--);
            for(j=i-1; j>=0 && s[j]!= ' '; j--);
            if(i<0) break;
            
            rev += s.substr(j+1, i-j);
            rev += ' ';
            i=j;
        }

        rev.pop_back();
        return rev;
    }
};