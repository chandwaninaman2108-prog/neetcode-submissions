class MedianFinder {
public:
    priority_queue<int>lower;
    priority_queue<int,vector<int>,greater<int>>upper;
    MedianFinder() {

    }
    
    void addNum(int num) {
        lower.push(num);

        upper.push(lower.top());
        lower.pop();
        if(lower.size()<upper.size()){
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if(lower.size()>upper.size()){
            return (double)lower.top();
        }
        return (lower.top()+upper.top())/2.0;
    }
};
