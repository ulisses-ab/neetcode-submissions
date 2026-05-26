class MedianFinder {
public:
    MedianFinder() {
        lower.push(-1e9);
        higher.push(-1e9);
    }
    
    void addNum(int num) {
        int l = lower.top(); lower.pop();
        int r = -higher.top(); higher.pop();

        if (lower.size() == higher.size()) {
            lower.push(l);
            lower.push(min(num, r));
            higher.push(-max(num, r));
        }
        else {  
            higher.push(-r);
            higher.push(-max(num, l));
            lower.push(min(num, l));
        }
    }
    
    double findMedian() {
        if (size() & 1) {
            return lower.top();
        }
        else {
            return double(lower.top() + -higher.top()) / 2;
        }
    }

    int size() {
        return lower.size() + higher.size();
    }

    priority_queue<int> lower, higher;
};
