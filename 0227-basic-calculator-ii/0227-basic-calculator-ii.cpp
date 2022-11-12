class Solution {
public:
    int calculate(string str) {
        
        string postfix;
        stack<char> s;
        stack<int> st;
        
        unordered_map<char, int> priority;
        
        priority['/'] = 1;
        priority['*'] = 1;
        priority['+'] = 0;
        priority['-'] = 0;

        
        for(int i=0; i<str.size(); i++){
            char ch = str[i];
            if(ch == ' ') continue;
            
            else if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){
                int j;
                for(j=i; j<str.size() && str[j]!=' ' && str[j]!='+' && str[j]!='-' && str[j]!='*' && str[j]!='/'; j++);
                postfix += str.substr(i, j-i);
                postfix += ' ';
                j--;
                i = j;
            }
            
            else if(s.size() == 0)
                s.push(ch);  
            
            else{
                while(!s.empty() && priority[s.top()] >= priority[ch]){
                    postfix += s.top();
                    s.pop();
                }
                s.push(ch);    
            }
        }
        
        while(!s.empty()){
            postfix += s.top();
            s.pop();
        }
        
        int n = postfix.size();
        
        for(int i=0; i<postfix.size();){
            if(postfix[i] == ' ') i++;
            
            else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                int ans;
                switch(postfix[i]){
                    case '+' : ans = num1+num2;break;
                    case '-' : ans = num2-num1;break;
                    case '*' : ans = num1*num2;break;
                    case '/' : ans = num2/num1;break;
                }
                st.push(ans);   
                i++;
            }
            
            else{
                int j;
                for(j=i; j<n && postfix[j]!=' '; j++);
                st.push(stoi(postfix.substr(i, j-i)));
                i = j;
            }
        }
        return st.top();
    }
};