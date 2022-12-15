class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        int ans = INT_MAX;
        unordered_map<int, set<int>> xmap;

        for(auto point: points){
            xmap[point[0]].insert(point[1]);
        }

        for(auto it1: xmap){
            if(it1.second.size()>=2){
                for(auto it2: xmap){
                    if(it2.second.size()>=2 && it1!=it2){
                        vector<int> common;

                        for(auto y: it1.second){
                            if(it2.second.find(y) != it2.second.end())
                                common.push_back(y);
                        }

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