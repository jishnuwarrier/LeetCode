class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();  
        sort(nums.begin() , nums.end());
        set<vector<int>> set;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long tgt = (long)target - nums[i] - nums[j];
                for(int k=j+1, l=n-1; k<l; ){
                    
                    long sum = nums[k]+nums[l];
                    if(sum < tgt) k++;
                    else if(sum > tgt) l--;
                    else
                        set.insert({nums[i], nums[j], nums[k++], nums[l--]});
                }
            }
        }
        
        return vector<vector<int>> (set.begin(), set.end());
    }
    
        
    };