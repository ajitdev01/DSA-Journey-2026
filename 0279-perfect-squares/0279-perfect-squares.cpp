// class Solution {
// public:
//     int numSquares(int n) {

//         vector<int> dp(n + 1, INT_MAX);

//         dp[0] = 0;

//         for (int i = 1; i <= n; i++) {

//             for (int j = 1; j * j <= i; j++) {

//                 dp[i] = min(dp[i], dp[i - j * j] + 1);

//             }
//         }

//         return dp[n];
//     }
// };






class Solution {
public:
    int numSquares(int n) {

       
        int x = sqrt(n);
        if (x * x == n) return 1;

        
        for (int i = 1; i * i <= n; i++) {
            int rem = n - i * i;
            int y = sqrt(rem);

            if (y * y == rem) return 2;
        }

        
        while (n % 4 == 0) {
            n /= 4;
        }

        if (n % 8 != 7) return 3;

        
        return 4;
    }
};