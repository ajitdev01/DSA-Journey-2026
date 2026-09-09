class Solution {
public:
    long long countCommas(long long n) {
       long long ans = 0;
       for(long long i = 1000; i<=n ; i*=1000){
         ans += n - i+1;

         if(i > n/1000)
           break;
       }
       return ans;
    }
};