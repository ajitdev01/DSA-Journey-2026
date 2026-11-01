class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());

        long long sum = 0;

        for (int x : nums) {
            sum += x;
        }

        return static_cast<int>(sum - 1LL * mn * nums.size());
    }
};