class Solution {
public:
    
    string count(string str){
        
        string ans;
        
        for(int i=0; i<str.size();){
            int j;
            for(j=i; j<str.size() && str[j] == str[i]; j++);
            ans.push_back('0'+(j-i));
            ans.push_back(str[i]);
            i = j;
        }
        return ans;
    }
    
    string countAndSay(int n) {
        
        string ans = "1";
        
        for(int i=1; i<n; i++){
            ans = count(ans);
        }

        
        return ans;
    }
};