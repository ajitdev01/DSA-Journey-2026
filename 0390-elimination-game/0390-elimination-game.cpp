// class solution {
// public:
//     int lastremaining(int n) {
//         int head = 1;
//         int step = 1;
//         int remaining = n;
//         bool lefttoright = true;

//         while (remaining > 1) {
//             if (lefttoright || remaining % 2 == 1) {
//                 head += step;
//             }

//             remaining /= 2;
//             step *= 2;
//             lefttoright = !lefttoright;
//         }

//         return head;
//     }
// };



//// More

class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, step = 1;
        bool left = true;

        while (n > 1) {
            if (left || n % 2 == 1)
                head += step;

            step <<= 1;
            n >>= 1;
            left = !left;
        }

        return head;
    }
};