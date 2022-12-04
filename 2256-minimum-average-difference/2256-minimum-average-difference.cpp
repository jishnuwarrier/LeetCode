class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n = nums.size();
        long long psum = 0, ssum = 0;
        for(auto num: nums) ssum += num;
        
        int minind = 0, currmin = INT_MAX;
        
        for(int i=0; i<n; i++){
            psum += nums[i];
            ssum -= nums[i];
            
            int diff = (i == n-1) ? psum/(i+1) : abs(psum/(i+1) - ssum/(n-i-1));
            if(diff < currmin){
                minind = i;
                currmin = diff;
            }
        }
        
        return minind;
    }
};