#include<bits/stdc++.h>
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.length();
        int MOD = 1000000007;
        vector<long long> dp(n + 1, 0);
        if(s[0] == '0') {
            return 0;
        } 
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            long long num = 0, mult = 1;
            for(int j = i; j >= 1; j--, mult *= 10) {
                num = num + mult * (s[j - 1] - '0');
                if(num > k || mult > k) {
                    break;
                }
                if(s[j - 1] != '0') {
                    dp[i] = (dp[i] + dp[j - 1]) % MOD;
                }
            }
        }
        return dp[n];
    }
};
