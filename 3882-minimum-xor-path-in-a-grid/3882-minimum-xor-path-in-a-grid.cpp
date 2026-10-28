class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<bitset<1024>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<1024> curr;

                if (i == 0 && j == 0) {
                    curr.set(grid[i][j]);
                } else {
                    if (i > 0) {
                        for (int x = 0; x < 1024; x++) {
                            if (dp[j][x]) {
                                curr.set(x ^ grid[i][j]);
                            }
                        }
                    }

                    if (j > 0) {
                        for (int x = 0; x < 1024; x++) {
                            if (dp[j - 1][x]) {
                                curr.set(x ^ grid[i][j]);
                            }
                        }
                    }
                }

                dp[j] = curr;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};