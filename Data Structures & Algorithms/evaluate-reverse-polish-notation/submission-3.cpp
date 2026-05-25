class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto token : tokens) {
            if (isdigit(token.back())) {
                int num = stoi(token);
                st.push(num);
                continue;
            }

            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int res;

            switch (token[0]) {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = b - a;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    res = b / a;
                    break;
            }

            st.push(res);
        }

        return st.top();
    }
};