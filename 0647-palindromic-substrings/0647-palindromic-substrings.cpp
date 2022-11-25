class Solution {
public:
    int ans = 0;
    
    void checkpal(string &s, int i, bool odd){
        int n = s.size();
        
        if(odd){
            for(int j=0; i+j<n && i-j>=0; j++)
                if(s[i+j] == s[i-j]) ans++;
                else break;
        }
        
        else{
            for(int j=0; i+1+j<n && i-j>=0; j++)
                if(s[i+1+j] == s[i-j]) ans++;
                else break;
        }
    }
    
    int countSubstrings(string s) {
        
        int n = s.size();
        
        for(int i=0; i<n; i++){
            checkpal(s, i, true);
            checkpal(s, i, false);
        }
        
        return ans;
    }
};