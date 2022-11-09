class StockSpanner {
public:
    
    stack<pair<int, int>> s;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span = 1;
        
        if(s.size()==0 || price < s.top().first)
            s.push({price, span});
        
        else{
            while(s.size() > 0 && price >= s.top().first){
                span += s.top().second;
                s.pop();
            }
            s.push({price, span});
        }
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */