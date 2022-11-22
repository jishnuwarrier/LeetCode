class Solution {
public:
    int numSquares(int n) {
       
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        int x = 1;
        int square = x*x;
        while(square <= n){
            for(int i=square; i<=n; i++){
                dp[i] = min(1+dp[i-square], dp[i]);
            }
            x++;
            square = x*x;
        }
        
        // for(auto x:dp)
        //     cout<<x<<" ";
                
        return dp[n];
    }
};