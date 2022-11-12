class Solution {
public:
    
    long int ans = 0;
    int high, low, zero, one;
    int mod = 1e9+7;
    vector<long int> dp;
    
    void recurse(int size){
        dp = vector<long int>(high+1, 0);
      
        for(int i=min(zero, one); i<=max(zero, one); i+=min(zero, one))
            dp[i] = 1;
        
        dp[max(zero, one)]++;
        
        for(int i=max(zero, one)+1; i<=high; i++){
            dp[i] = dp[i-zero] + dp[i-one];
            dp[i] = dp[i]%mod;
        }
    }
    
    int countGoodStrings(int l, int h, int z, int o) {

        low = l;
        high = h;
        zero = z;
        one = o;
        
        recurse(0);

        
        for(int i=low; i<=high; i++){
            ans += dp[i];
            ans = ans%mod;
        }
        
        return ans;
    }
};