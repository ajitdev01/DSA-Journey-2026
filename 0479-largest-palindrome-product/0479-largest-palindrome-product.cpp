class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        long long high = 1;
        for (int i = 0; i < n; i++)
            high *= 10;
        high--;

        long long low = high / 10 + 1;

        for (long long left = high; left >= low; --left) {
            string s = to_string(left);
            string r = s;
            reverse(r.begin(), r.end());

            long long pal = stoll(s + r);

            for (long long x = high; x * x >= pal; --x) {
                if (pal % x == 0) {
                    long long y = pal / x;

                    if (y >= low && y <= high)
                        return pal % 1337;
                }
            }
        }

        return -1;
    }
};