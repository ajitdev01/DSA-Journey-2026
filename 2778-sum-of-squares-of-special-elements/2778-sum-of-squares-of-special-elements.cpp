
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int i = 1; i <= n; i += 1) {
            if (n % i == 0)
                ans += nums[i - 1] * nums[i - 1];
        }

        return ans;
    }
};
