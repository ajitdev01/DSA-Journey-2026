class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        long long left = 1, right = x;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (mid <= x / mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};