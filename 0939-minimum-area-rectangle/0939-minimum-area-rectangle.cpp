class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        int ans = INT_MAX;
        unordered_map<int, unordered_set<int>> xmap;

        for(auto point: points){
            xmap[point[0]].insert(point[1]);
        }

        for(auto it1: xmap){
            if(it1.second.size()>=2){
                for(auto it2: xmap){
                    if(it2.second.size()>=2 && it1!=it2){
                        unordered_set<int> &s1 = it1.second;
                        unordered_set<int> &s2 = it2.second;

                        vector<int> common;

                        for(auto y: s1){
                            if(s2.find(y) != s2.end())
                                common.push_back(y);
                        }

                        sort(common.begin(), common.end());
                        int l = abs(it1.first - it2.first);

                        for(int i=1; i<common.size(); i++){
                            int b = common[i]-common[i-1];
                            ans = min(ans, l*b);
                        }

                    }
                }
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};