class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        
        int evensum = 0;
        for(auto num: nums){
            if(num%2 == 0)
                evensum += num;
        }
        
        for(auto q: queries){
            if(nums[q[1]]%2 == 0){
                if(q[0]%2 == 0){
                    evensum += q[0];
                }
                else{
                    evensum -= nums[q[1]];
                }
                
                nums[q[1]] += q[0];
            }
            
            else{
                nums[q[1]] += q[0];
                
                if(q[0]%2 != 0){
                    evensum += nums[q[1]];
                }
            }
            
            ans.push_back(evensum);
        }
        
        return ans;
    }
};