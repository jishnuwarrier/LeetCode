class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> maxleft(n, 0);
        vector<int> maxright(n, 0);
        
        for(int i=1; i<n; i++){
            maxleft[i] = max(maxleft[i-1], height[i-1]);
            maxright[n-i-1] = max(maxright[n-i], height[n-i]);
        }
       
        int vol = 0;
        
        for(int i=0; i<n; i++)
            vol += max(min(maxleft[i], maxright[i]) - height[i], 0);
      
        return vol;
    }
};