class Solution {
public:
    
    bool checkpal(string palindrome){
        int l=0, r=palindrome.size()-1;
        
        while(l<r){
            if(palindrome[l++] != palindrome[r--])
                return false;
        }
        
        return true;
    }
    
    string breakPalindrome(string palindrome) {
        
        int n = palindrome.size();
        
        if(n == 1)
            return "";
        
        
        for(int i=0; i<n; i++){            
            
            if(n%2 == 1 && i == n/2)
                continue;
            
            if(palindrome[i] != 'a')
                palindrome[i] = 'a', i=n;
  
            if(i == n-1)
                palindrome[i] = 'b';
        }
        
        return palindrome;
    }
};