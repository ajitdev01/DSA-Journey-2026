class Solution {
public:
    bool isPowerOfFour(int n) {
        ////// O(n)
        // if(n <= 0) return false;
        // while(n%4==0){
        //     n /= 4;
        // }
        // return n ==1 ;


        ///// O(1)
        if(n <= 0 ) return false;

        if ((n & (n-1)) !=  0) return false;

        return (n & 0x55555555) != 0;
    }
};