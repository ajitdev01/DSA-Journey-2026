class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {0};

        // Count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxOdd = 0;
        int minEven = INT_MAX;

        // Find max odd and min even frequency
        for (int count : freq) {
            if (count == 0) continue;

            if (count % 2 == 1) {
                maxOdd = max(maxOdd, count);
            } else {
                minEven = min(minEven, count);
            }
        }

        return maxOdd - minEven;
    }
};