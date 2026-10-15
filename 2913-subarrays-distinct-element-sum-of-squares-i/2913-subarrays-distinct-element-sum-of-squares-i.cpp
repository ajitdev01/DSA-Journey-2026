class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int freq[101] = {};
            int distinct = 0;

            for (int j = i; j < n; j++) {
                if (freq[nums[j]]++ == 0) {
                    distinct++;
                }

                ans += distinct * distinct;
            }
        }

        return ans;
    }
};