class Solution {
public:

    struct comp {
        bool operator()(string const &i, string const &j) const {
            return i+j > j+i;
        }
    };
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> str;
        for(auto num: nums) 
            str.push_back(to_string(num));
        
        sort(str.begin(), str.end(), comp());
        string ans = "";
        for(auto num: str) 
            ans += (num);
        
        return (ans[0] == '0') ? "0" : ans;
    }
};