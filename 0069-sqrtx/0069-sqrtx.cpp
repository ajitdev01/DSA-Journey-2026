class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        long left = 1, right = x, ans = 0;

        while (left <= right) {
            long mid = left + (right - left) / 2;

            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid < x) {
                ans = mid;      // store possible answer
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};