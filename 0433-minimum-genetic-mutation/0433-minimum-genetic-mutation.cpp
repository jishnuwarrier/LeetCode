class Solution {
public:
    
    bool dist(string s1, string s2){
        int count = 0;
        for(int i=0; i<8; i++)
            if(s1[i] != s2[i])
                count++;
        
        return (count == 1) ? true : false;
    }
        
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string> set;        
        queue<string> q;
        q.push(start);
        
        for(int steps=0; !q.empty(); steps++){
            int size = q.size();
            while(size-- > 0){
                string str = q.front();
                q.pop();
                
                if(str == end) return steps;
                
                for(int i=0; i<bank.size(); i++){
                    if(dist(str, bank[i]) && set.find(bank[i])==set.end())
                        set.insert(bank[i]), q.push(bank[i]);
                }
            }
        }
        
        return -1;
    }
};