class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        vector<int> a = {ax1, ax2, ay1, ay2};
        vector<int> b = {bx1, bx2, by1, by2};
        
        a.push_back((ax2-ax1) * (ay2-ay1));
        b.push_back((bx2-bx1) * (by2-by1));
        
        if(ax2 > bx2)
            swap(a, b);
                
        if((b[0]<=a[0]) && b[2]<=a[2] && b[3]>=a[3])
            return b[4];        

        if(b[0]>=a[1] || a[2]>=b[3] || b[2]>=a[3])
            return (a[4]+b[4]);
        
        return (a[4] + b[4] - (a[1]-max(a[0], b[0])) * (min(a[3], b[3]) - max(a[2], b[2])));
    }
};