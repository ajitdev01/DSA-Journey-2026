class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // Paths entering each cell from above (moving down).
        vector<int> down(n, 0);

        for (int i = 0; i < m; i++) {
            // Paths entering from the left (moving right).
            int right = 0;

            for (int j = 0; j < n; j++) {
                int fromLeft = right;
                int fromAbove = down[j];

                if (grid[i][j] == 0) {
                    // Empty cell: combine both incoming directions.
                    int ways;

                    if (i == 0 && j == 0) {
                        ways = 1;
                    } else {
                        ways = (fromLeft + (long long)fromAbove) % MOD;
                    }

                    if (i == m - 1 && j == n - 1) {
                        return ways;
                    }

                    // Can move right or down.
                    right = ways;
                    down[j] = ways;
                } 
                else {
                    // Mirror:
                    // Entering from left -> reflected down.
                    // Entering from above -> reflected right.
                    right = fromAbove;
                    down[j] = fromLeft;
                }
            }
        }

        return 0;
    }
};