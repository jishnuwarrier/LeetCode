class Solution {
public:
    bool containsNearbyDuplicate(vector<int>&nums, int k) {
        
        if(k == 0)
            return false;
        
        int m = nums.size();        
        unordered_map<int, vector<int>> map;
        
        for(int i=0; i<m; i++)
            map[nums[i]].push_back(i);
        
        for(auto it: map){
            int n = it.second.size();
            for(int i=0, j=1; j<n; i++, j++){
                if((it.second[j]-it.second[i]) <= k){
                    cout<<it.second[i]<<" "<<it.second[j]<<endl;
                    return true;
                }
            }

        }
        
        return false;
    }
};