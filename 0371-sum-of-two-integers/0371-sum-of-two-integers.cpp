class Solution {
public:
    int getSum(int a, int b) {

        int sign = (a>0 || b>0) ? 1 : -1;
        
        if(a<0 && b<0)
            a = -a,
            b = -b;
        
        if(abs(a) < abs(b)) swap(a, b);
        
        if(b == 0) return a;
        
        if(a<0 && b>0){
            a = -a;
            b = -b;
            sign *= -1;
        }
        
        int carry = 0;
        int ans = 0;
        
        for(int i=0; a>0 || b>0 || carry != 0; i++, a/=2, b/=2){
            
            int x=a%2, y=b%2;
            ans += pow(2,i)*((x)^(y)^carry);
            carry = (x&y)||(y&carry)||(x&carry);
        }
        
        return sign*ans;
    }
};