class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        long long upper = pow(10, n) - 1;
        long long lower = pow(10, n - 1);

        for (long long left = upper; left >= lower; --left) {
            // Create palindrome: left + reverse(left)
            string s = to_string(left);
            string rev = s;
            reverse(rev.begin(), rev.end());

            long long palindrome = stoll(s + rev);

            // Check whether palindrome = x * y
            for (long long x = upper; x * x >= palindrome; --x) {
                if (palindrome % x == 0) {
                    long long y = palindrome / x;

                    if (y >= lower && y <= upper) {
                        return palindrome % 1337;
                    }
                }
            }
        }

        return -1;
    }
};