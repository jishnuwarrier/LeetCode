class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        
        int n = nums.size();
        stack<int> s1, s2;
        vector<int> left(n);
        vector<int> right(n);
        
        for(int i=0; i<n; i++) left[i] = i+1;
        for(int i=0; i<n; i++) right[i] = n-i;
        
        for(int i=0; i<n; i++){
            
            while(!s1.empty() && nums[s1.top()] > nums[i])
                s1.pop();
            left[i] = (s1.empty()) ? i+1 : i - s1.top();
            s1.push(i);
            
            while(!s2.empty() && nums[s2.top()] > nums[i]){
                right[s2.top()] = i - s2.top();
                s2.pop();
            }
            s2.push(i);
        }
        
        long long ans = 0;
        int mod = 1e9+7;
        for(int i=0; i<n; i++)
            ans = (ans + (long long)nums[i] * left[i] * right[i]) % mod;
    
        return ans;
    }
};