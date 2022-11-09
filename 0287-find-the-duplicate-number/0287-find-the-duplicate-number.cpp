class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow=nums[0], fast=nums[nums[0]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        for(int slow1=0; slow != slow1; slow=nums[slow], slow1=nums[slow1]);
        return slow;
    }
};