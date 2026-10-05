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
                int current = st.top();
                st.pop();

                int score = (current == 0) ? 1 : 2 * current;

                st.top() += score;
            }
        }

        return st.top();
    }
};