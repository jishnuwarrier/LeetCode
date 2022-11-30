class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int> set;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int curr;
        for(int i=0; i<n;){
            int j;
            for(j=i; j<n && arr[i]==arr[j]; j++); 
            if(set.find(j-i) != set.end()) return false;
            set.insert(j-i);
            
            i=j;
        }
        
        return true;
    }
};