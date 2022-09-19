class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        int vol = 0;
        int l=0, r=n-1;
        int lmax=0, rmax = 0; 
                
        while(l <= r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            
            if(lmax < rmax)
                vol += lmax - height[l++];
    
            else
                vol += rmax - height[r--];
        }
        return vol;
    }
};