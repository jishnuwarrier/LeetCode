//         unordered_map<string, int> dict;
//         for(auto word: wordDict)
//             dict[word] = 1;
//         for(auto word: dict)
//             cout<<word.first<<" "<<word.second<<endl;
for(int i=0; i<s.size(); ){
int j = i;
for(auto word: wordDict){
if(i+word.size() > s.size())
continue;
string str = s.substr(i, word.size());
if(str == word)
i += word.size();
}
if(i == j)
return false;
}
return true;