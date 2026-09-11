//// Run This Code

// class Solution {
// public:
//     int countCommas(int n) {
//         if(n < 1000)
//             return 0;
            
//         return n - 999;
//     }
// };


////// more optimized
class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;

        for (long long x = 1000; x <= n; x *= 1000) {
            ans += n - x + 1;
            
            if (x > n / 1000)
                break;
        }

        return ans;
    }
};

