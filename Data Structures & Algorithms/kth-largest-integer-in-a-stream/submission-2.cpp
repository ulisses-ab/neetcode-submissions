class KthLargest {
public:
    KthLargest(int k_, vector<int>& nums) {
        k = k_;
        for (auto x : nums) {
            add(x);
        }
    }
    
    int add(int val) {
        if (pq.size() < k) {
            pq.push(-val);
            return -pq.top();
        }

        if (val <= -pq.top()) {
            return -pq.top();
        }

        pq.pop();
        pq.push(-val);

        return -pq.top();
    }

    priority_queue<int> pq;
    int k;
};
