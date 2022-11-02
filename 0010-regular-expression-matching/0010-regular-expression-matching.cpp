class Solution {
public:
    int m, n;
    string s,p;
    
    bool dfs(int i, int j){

        if(i>=m && j>=n) return true;
        if(j>=n) return false;
        
        if(i>=m){
            while(j<n-1 && p[j+1]=='*')
                j+=2;
            
            return (j>=n);
        }
        
        bool check = (s[i]==p[j] || p[j]=='.');
          
        if(j<n-1 && p[j+1]=='*')
            return (check) ? (dfs(i+1,j) || dfs(i,j+2)) : dfs(i,j+2);
        
        else if(check  == true)
            return dfs(i+1, j+1);
        
        return false;
    }
    
    bool isMatch(string s1, string s2) {
        s=s1, p=s2;
        m=s.size(), n=p.size();
        return dfs(0, 0);
    }
};