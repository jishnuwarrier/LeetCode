class Solution {
public:    
    int lengthOfLongestSubstring(string s) {

        int n = s.size(), ans = 0;
        unordered_map<char, int> latestPost;
        int l = -1;
        for(int r = 0; r<n; r++){
            if(latestPost.find(s[r]) != latestPost.end())
                l = max(l, latestPost[s[r]]);
            latestPost[s[r]] = r;
            ans = max(ans, r - l);
        }
        
        return ans;
    }
};