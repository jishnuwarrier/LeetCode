class Solution {
public:
    int maximum69Number (int num) {

        for(int i=3; i>=0; i--){
            int temp = 10*(int)(num/(pow(10,i+1))); 
            int digit = (num/pow(10, i) - 10*(int)(num/(pow(10,i+1))));
            if(digit == 6){
                num += 3*pow(10,i);
                return num;
            }
        }
        
        return num;
    }
};