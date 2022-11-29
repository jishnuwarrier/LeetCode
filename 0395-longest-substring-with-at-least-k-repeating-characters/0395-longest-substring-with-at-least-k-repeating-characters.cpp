class Solution {
public:
    int longestSubstring(string s, int k) {
        
        if(k == 1) return s.size();
        
        int n = s.size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            vector<int> freq(26, 0);
            int count = 0;
            for(int j=i; j<n; j++){
                if(freq[s[j]-'a'] == 0) count++;
                freq[s[j]-'a']++;
                if(freq[s[j]-'a'] == k)
                    count--;
                
                if(count == 0) ans = max(ans, j-i+1);
            }
        }
        
        return ans;
    }
};