class Solution {
public:
    string makeGood(string str) {
        string ans;
        stack<char> s;
        
        for(int i=0; i<str.size(); i++){
           if(s.empty())
               s.push(str[i]);
            
            else{
                if(str[i]+32==s.top() || s.top()+32==str[i])
                    s.pop();
                
                else
                    s.push(str[i]);
            }
        }   

        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};