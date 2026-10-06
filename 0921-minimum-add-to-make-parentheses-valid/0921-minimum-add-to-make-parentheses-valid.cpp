// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         int open = 0;
//         int ans = 0;

//         for (char ch : s) {
//             if (ch == '(') {
//                 open++;
//             } else {
//                 if (open > 0) {
//                     open--;
//                 } else {
//                     ans++;
//                 }
//             }
//         }

//         return ans + open;
//     }
// };



////////


class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0, ans = 0;

        for (char ch : s) {
            if (ch == '(') {
                balance++;
            } else if (balance > 0) {
                balance--;
            } else {
                ans++;
            }
        }

        return ans + balance;
    }
};
