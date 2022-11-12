class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
                
        left.push(num);
        right.push(left.top());
        left.pop();
        
        if(left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size())
            return ((double)left.top() + right.top())/2;
        
        
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */