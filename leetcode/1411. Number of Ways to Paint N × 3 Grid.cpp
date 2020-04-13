class Solution {
public:
    int numOfWays(int n) {
        long long a123 = 6, a121 = 6, b123, b121, mod = 1000000007;
        for(int i = 2; i <= n; i++) {
            b121 = ((2 * a123) % mod + (2 * a121) % mod) % mod;
            b123 = ((3 * a123) % mod + (2 * a121) % mod) % mod;
            a123 = b123 % mod;
            a121 = b121 % mod;
        }
        return ((a121 % mod) + (a123 % mod)) % mod;
    }
};
