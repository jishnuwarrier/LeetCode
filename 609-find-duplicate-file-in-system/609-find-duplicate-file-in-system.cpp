class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string, vector<string>> map;
        
        for(auto str: paths){
            string src;
            int i;
            for(i=0; i<str.length(); i++){
                if(str[i] == ' ')
                    break;
                else
                    src.push_back(str[i]);
            }

            for(++i; i<str.length(); i++){
                string file, content;
                for(; i<str.length() && str[i] != ' '; i++){
                    
                    while(str[i] != '(')
                        file.push_back(str[i++]);
    
                    if(str[i++] == '('){
                        while(str[i] != ')')
                            content.push_back(str[i++]);
                    }
                }
                map[content].push_back(src+'/'+file);
            }
        }

        vector<vector<string>> ans;
        
        for(auto it: map){
            vector<string> v;
            if(it.second.size() > 1){
                for(auto str: it.second){
                    v.push_back(str);
                }
            }
            if(v.size() > 0)
                ans.push_back(v);
        }
        
        return ans;
    }
};