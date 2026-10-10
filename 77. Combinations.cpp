class Solution {
public:
    void backtrack(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

      
        int limit = n - (k - current.size()) + 1;
        for (int i = start; i <= limit; ++i) {
            current.push_back(i);
            backtrack(n, k, i + 1, current, result);
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(n, k, 1, current, result);
        return result;
    }
};
