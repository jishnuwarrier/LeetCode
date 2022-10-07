class MyCalendarThree {
public:
    map<int, int> map;
    int maxbook = 0;
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        map[start]++;
        map[end]--;
        
        int count = 0;
        
        for(auto it = map.begin(); it != map.end(); it++){
            count += it->second;
            maxbook = max(maxbook, count);
        }
        
        return maxbook;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */