
class Solution {
public:
    vector<int> mp[6][6];
    unordered_map<string, bool> memo;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto& s : allowed) {
            mp[s[0] - 'A'][s[1] - 'A'].push_back(s[2] - 'A');
        }

        return dfs(bottom);
    }

    bool dfs(string& row) {
        if (row.size() == 1)
            return true;

        if (memo.count(row))
            return memo[row];

        string next = "";
        return memo[row] = build(row, 0, next);
    }

    bool build(string& row, int i, string& next) {
        if (i == (int)row.size() - 1)
            return dfs(next);

        for (int c : mp[row[i] - 'A'][row[i + 1] - 'A']) {
            next.push_back(char('A' + c));

            if (build(row, i + 1, next))
                return true;

            next.pop_back();
        }

        return false;
    }
};
