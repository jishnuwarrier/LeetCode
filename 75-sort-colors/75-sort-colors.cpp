class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        vector<int> freq(3, 0);
        
        for(auto num: nums)
            freq[num]++;
        
        for(int i=0; i<freq[0]; i++)
            nums[i] = 0;
        
        for(int i=freq[0]; i<freq[0]+freq[1]; i++)
            nums[i] = 1;

        for(int i=freq[0]+freq[1]; i<freq[0]+freq[1]+freq[2]; i++)
            nums[i] = 2;
        
    }
};