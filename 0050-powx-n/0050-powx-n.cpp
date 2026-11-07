class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        long double base = x;
        long double ans = 1.0L;

        if (exp < 0) {
            base = 1.0L / base;
            exp = -exp;
        }

        while (exp > 0) {
            if (exp & 1LL) {
                ans *= base;
            }

            base *= base;
            exp >>= 1;
        }

        return static_cast<double>(ans);
    }
};