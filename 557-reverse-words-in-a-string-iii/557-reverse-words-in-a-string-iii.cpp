class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size();
        
        for(int i=0; i<n; i++){
            int j = i;
            for(;j != n && s[j] != ' '; j++);            

            if(j == n)
                reverse(s.begin()+i, s.begin()+j);
            else
                reverse(s.begin()+i, s.begin()+j);
            
            i = j;
        }
        
        return s;
    }
};