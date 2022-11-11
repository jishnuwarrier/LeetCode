class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int dup=0;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1])
                nums[i] = INT_MIN,
                dup++;
        }
        
        int size = n-dup;
        
        for(int i=0; i<size; i++){
            if(nums[i] == INT_MIN){
                int j = i+1;
                while(j<n && nums[j]==INT_MIN)
                    j++;
                
                auto temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        
        return size;
    }
};