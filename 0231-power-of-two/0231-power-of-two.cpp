class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        //// O(n)
        // if(n <= 0 ) return false;
        // while(n % 2 == 0 ){
        //     n/= 2;
        // }
        // return n == 1;

        //// O(1) simple way
        if(n <= 0) return false;
        return ( n & (n-1) ) == 0;

    }
};