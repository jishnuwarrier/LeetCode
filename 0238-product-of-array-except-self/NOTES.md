int n = nums.size();
vector<int> ans, prefix, suffix;
for(int i=0, prod=1; i<n;i++){
prefix[i] = prod;
prod *= nums[i];
}
for(int i=n-1, prod=1; i>=0; i--){
suffix[i] = prod;
prod *= nums[i];
}
for(int i=0; i<n; i++)
ans.push_back(prefix[i] * suffix[i]);
return ans;