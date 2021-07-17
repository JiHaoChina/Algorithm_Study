class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> small;   
    priority_queue<int, vector<int>, less<int>> big;

public:  
    void addNum(int num) {
        big.push(num);
        int most = big.top();
        big.pop();
        small.push(most);
        if (big.size() < small.size()) {
            int least = small.top();
            small.pop();
            big.push(least);
        }
    }
    
    double findMedian() {
        if (big.size() == small.size()) {
            return (big.top() + small.top())*0.5;
        }
        else {
            return big.top();
        }

    }
};