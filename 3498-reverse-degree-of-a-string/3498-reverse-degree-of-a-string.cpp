class Solution {
public:
    int reverseDegree(string s) {
        int n = 0;

        for (int i = 0; i < s.length(); i++) {
            n += (i + 1) * (26 - (s[i] - 'a'));
        }

        return n;
    }
};