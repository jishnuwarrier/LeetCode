class Solution {
public:
    
    string helper(string s, int &pos){
                
        int n = s.size();
        int num = 0;
        string ans;
        for(; pos<n ; pos++){
            
            if(s[pos] == '['){
                string rep = helper(s, ++pos);
                for(; num>0; num--)
                    ans+=rep;
            }
            else if(s[pos]>='0' && s[pos]<='9'){
                num = num*10 + (s[pos]-'0');
            }
            else if(isalpha(s[pos]))
                ans += s[pos];
            
            else
                return ans;
        }
        return ans;
    }
    
    string decodeString(string s) {
        int pos = 0;
        return helper(s, pos);
    }
};