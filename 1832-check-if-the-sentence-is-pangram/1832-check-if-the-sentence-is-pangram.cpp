class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<int> v(26, 0);
        
        for(auto ch: sentence)
            v[ch-'a']++;
        
        for(auto num: v)
            if(num == 0)
                return false;
               
        return true;
    }
};