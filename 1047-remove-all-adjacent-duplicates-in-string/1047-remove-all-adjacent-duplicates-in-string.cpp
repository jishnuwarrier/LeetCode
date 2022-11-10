class Solution {
public:
    string removeDuplicates(string str) {
        
        stack<char> s;
        
        for(auto ch: str){
            if(s.size()==0 || ch!=s.top())
                s.push(ch);
            
            else if(ch == s.top())
                s.pop();
        }
        
        string ans;
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};