class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tgt) {
        
        int ans = 10000000;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++){
            int l = i+1, r = n-1;
            
            int sum;
            while(l<r){
                sum = nums[i]+nums[l]+nums[r];
                
                if(abs(sum-tgt) < abs(ans-tgt))
                    ans = sum;
                
                (sum < tgt) ? l++: r--;
            }
        }
        
        return ans;
    }
};