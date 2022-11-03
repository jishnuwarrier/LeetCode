class Solution {
public:

    int longestPalindrome(vector<string>& words) {
        
        int count = 0;
        map<string, int> map;
        
        int w=0;
        for(int i=0; i<words.size(); i++)
            map[words[i]]++;
           
        for(auto it: map){
            string word = it.first;
            int freq = it.second;
            
            string rev;
            rev += word[1], rev += word[0];
            
            if(word == rev){
                if(count%4 == 0)
                    count += 2*(map[word]);
                else
                    count += 2*(map[word]-map[word]%2);

                map[word] = 0;
            }
            
            else{
                count += 4*min(map[word], map[rev]);
                map[word]=0, map[rev]=0;
            }
        }
        

        return count;
    }
};