class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int smallest = val;
        
        if (!st.empty()) {
            smallest = min(smallest, st.top().second);
        }

        st.push({val, smallest});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }

    stack<pair<int, int>> st;
};