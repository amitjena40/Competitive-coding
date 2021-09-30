class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (char c : s) {
            if (c == '(') {
                st.push(0);
            }
            else {
                int x = st.top();
                st.pop();
                x = ((x == 0) ? 1 : 2 * x) + st.top();
                st.pop();
                st.push(x);
            }
        }
        return st.top();
    }
};