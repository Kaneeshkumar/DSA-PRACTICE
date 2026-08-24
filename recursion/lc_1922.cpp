class Solution {
public:
    long long mod = 1e9 + 7;

    long long f(long long x, long long n){
        long long ans = 1;
        x = x % mod;
        while(n > 0){
            if(n % 2 == 1){
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            n = n / 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long forOdd = n / 2;
        long long forEven = n - forOdd;

        long long totalOdd = f(4, forOdd);
        long long totalEven = f(5, forEven);

        long long ans = (totalOdd * totalEven) % mod;
        return (int)ans;
    }
};