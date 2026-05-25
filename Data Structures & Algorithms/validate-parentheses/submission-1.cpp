class Solution {
public:
    bool is_opening(char c) {
        return    
            c == '(' || 
            c == '{' ||
            c == '[';
    }

    char opening_match(char c) {
        switch (c) {
            case ')': return '(';
            case ']': return '[';
            case '}': return '{';
        }
    }

    bool isValid(string s) {
        stack<char> st;
        
        for (auto c : s) {
            if (is_opening(c)) {
                st.push(c);
                continue;
            }

            if (
                st.empty() ||
                st.top() != opening_match(c)
            ) {
                return false;
            }

            st.pop();
        }

        if (!st.empty()) return false;

        return true;
    }
};
