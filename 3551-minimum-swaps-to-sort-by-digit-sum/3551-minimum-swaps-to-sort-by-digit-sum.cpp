class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a;
        a.reserve(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            a.emplace_back(sum, nums[i]);
        }

        sort(a.begin(), a.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[i] = a[i].second;
        }

        unordered_map<int, int> idx;
        idx.reserve(n);
        for (int i = 0; i < n; i++) {
            idx[nums[i]] = i;
        }

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || idx[pos[i]] == i)
                continue;

            int j = i, cycle = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = idx[pos[j]];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};