class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a = 0, b = INT_MAX, c = INT_MAX;

        for (int i = 1; i <= n; i++) {
            int curr = a + 1;

            if (i >= 2)
                curr = min(curr, b + 4);

            if (i >= 3)
                curr = min(curr, c + 9);

            curr += costs[i - 1];

            c = b;
            b = a;
            a = curr;
        }

        return a;
    }
};