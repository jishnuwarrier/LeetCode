class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> v(n);
        
        int l = (n-1)/2, r = n-1;
        
        for(int i=0; i<n; i++)
            v[i] = (i%2 == 0) ? nums[l--] : nums[r--];
        
        nums = v;
    }
};