class Solution {
public:
    int countCommas(int n) {
        int ans = 0;

        // 1,000 to n → 1 comma each
        if (n >= 1000) {
            ans += n - 999;
        }

        // 1,000,000+ would have 2 commas,
        // but n <= 10^5, so this case never occurs.

        return ans;
    }
};