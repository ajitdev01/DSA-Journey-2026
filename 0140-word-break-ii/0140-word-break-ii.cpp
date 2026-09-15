class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;
    string s;

    vector<string> dfs(int start) {
        if (memo.count(start))
            return memo[start];

        vector<string> result;

    
        if (start == s.size()) {
            result.push_back("");
            return result;
        }

        
        for (int end = start; end < s.size(); end++) {
            string word = s.substr(start, end - start + 1);

            if (!dict.count(word))
                continue;

            vector<string> suffixes = dfs(end + 1);

            for (string& suffix : suffixes) {
                if (suffix.empty())
                    result.push_back(word);
                else
                    result.push_back(word + " " + suffix);
            }
        }

        return memo[start] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s;

        for (const string& word : wordDict)
            dict.insert(word);

        return dfs(0);
    }
};