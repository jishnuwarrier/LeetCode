class Solution {
public:
        
    bool isUgly(int n) {
        
        if(n<1) return false;
        
        vector<int> factors = {2,3,5};
        for(auto factor: factors){
            for(; n%factor==0; n/=factor);
        }
        
        return n==1;
    }
};