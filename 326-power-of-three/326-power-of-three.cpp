class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n <= 0)
            return false;
        
        while(n!= 1 && n!= INT_MAX)
            (n%3 == 0) ? n/= 3 : n=INT_MAX;    
        
        if(n == 1)
            return true;
        else
            return false;
    }
};