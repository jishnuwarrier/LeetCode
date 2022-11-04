class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vow;
        vector<int> pos;
        
        for(int i=0; i<s.size(); i++){
            
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U') 
                continue;
           
            vow.push_back(s[i]);
            pos.push_back(i);
        }
        
        for(int i=0; i<pos.size(); i++)
            s[pos[i]] = vow[vow.size()-i-1];
        
        return s;
    }
};