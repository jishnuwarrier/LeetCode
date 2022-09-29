class Solution {
public:
    
    //Using Prefix sum
    int numberOfSubarrays(vector<int>& nums, int k){
      
        unordered_map<int, int> map;
        map[0]++;
        
        int sum = 0, ans = 0;
        
        for(auto num: nums){
            num = num%2;
            
            sum += num;
            map[sum]++;
            
            ans += map[sum - k];
        }
        
        return ans;
    }
    
    
    //Using Two Pointers
//     int numberOfSubarrays(vector<int>& nums, int k) {
            
//             int n = nums.size();
//             int ans = 0;
//             int odd = 0, l = 0, r = 0;
        
//             for(int r=0; r<n; r++){
                
//                 int len1 = 0, len2 = 0;
                
//                 if(nums[r]%2 == 1){
//                     odd++;
//                     continue;
//                 }
                
//                 while(odd >= k){
//                     if(nums[l++]%2 == 1)
//                         odd--;
//                 }
                                
//                 if(odd == k){
//                     while(nums[l]%2 == 0)
//                         len1++, l++;
                    
//                     r++;
//                     while(nums[r] %2 == 0)
//                         len2++, r++;
                    
//                     ans += len1*len2;
//                 }
                    
//             }
//         cout<<l<<" "<<r;
//         return ans;
//     }
};