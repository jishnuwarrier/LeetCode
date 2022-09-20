class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size(), n = nums2.size(), maxlen = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i==0 || j==0) && nums1[i] == nums2[j])
                    dp[i][j] = 1;
                
                else if((i!=0 && j!=0) && nums1[i] == nums2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                
                else
                    dp[i][j] = 0;
                
                maxlen = max(maxlen, dp[i][j]);
            }  
        }

        return maxlen;
    }
};