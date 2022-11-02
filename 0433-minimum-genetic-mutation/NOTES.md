for(int i=0; set.size()<bank.size() && i<10; i++){
if(i==j) continue;
if(set.find(bank[j]) == s.end() && dist(bank[i], bank[j]))
map[bank[i]].push_back(bank[j]);
}