class MyCalendar {
public:
    map<int, int> map;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto it = map.begin(); it != map.end(); it++){

            if(it->first >= end)
                break;
            
            if((it->first >= start && it->first < end) || (it->second >start && it->second < end))
                return false;   
            
            if(it->first < start && it->second > start)
                return false;
        }        
        
        map[start] = end;
        cout<<"Booked "<<start<<" "<<end<<endl;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */