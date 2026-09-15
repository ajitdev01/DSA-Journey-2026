class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        long long maxArea = 0;

        stack<int> st;

        for (int i = 0; i <= n; ++i) {
            int curr = (i == n ? 0 : heights[i]);

            while (!st.empty() && heights[st.top()] > curr) {
                int h = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                maxArea = max(maxArea, 1LL * h * width);
            }

            if (i < n)
                st.push(i);
        }

        return static_cast<int>(maxArea);
    }
};