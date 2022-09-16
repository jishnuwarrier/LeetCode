class Solution {
public:
    string convert(string s, int r) {
        
        if(r == 1)
            return s;
        
        int n = s.length();
        string ans = "";
        int f=2*r-4, l=2;
                
        for(int i=0; i<r; i++){
      
            int k = i;
            
            if(i == 0 || i == r-1){
                while(k < n){
                    ans.push_back(s[k]);
                    k += (2*r - 2);

                }
            }
            
            else{
                while(k<n){
                    ans.push_back(s[k]);
                    k += f;

                    if(k<n){
                        ans.push_back(s[k]);  
                        k += l;
                    }
                }
                
                f -= 2;
                l += 2;
            }

        }
        
        return ans;
    }
};