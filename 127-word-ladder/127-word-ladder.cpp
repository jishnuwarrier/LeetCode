class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> set(wordList.begin(), wordList.end());
        
        if(set.find(endWord) == set.end())
            return 0;
        
        int n = beginWord.size();
        
        queue<string> q;
        q.push(beginWord);
        int ans = 2;
        
        for(; q.empty() == false; ans++){
            
            int size = q.size();
            
            for(; size>0; size--){

                string word = q.front();
                string temp;
                q.pop();

                for(int j=0; j<n; j++){
                    temp = word;
                    for(int k=0; k<26; k++){
                        if(word[j] == ('a'+k))
                            continue;

                        temp[j] = 'a'+k;

                        if(temp == endWord)
                            return ans;

                        if(set.find(temp) != set.end()){
                            cout<<temp<<" "<<ans<<endl;
                            q.push(temp);
                            set.erase(temp);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};