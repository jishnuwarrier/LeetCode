class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> v(m+n);
        
        int i=0, x=0, y=0;
        for(; i<v.size() && x<m && y<n; i++)
            v[i] = (nums1[x] <= nums2[y]) ? nums1[x++] : nums2[y++];
        
        while(x<m)
            v[i++] = nums1[x++];
        
        while(y<n)
            v[i++] = nums2[y++];
            
        nums1 = v;
    }
};