class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= heights.size(); i++) {
            int currHeight = (i == heights.size()) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currHeight) {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};