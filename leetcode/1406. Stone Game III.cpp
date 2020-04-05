#define INT_MIN -1e9

class Solution {
public:
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MIN);
        for(int i = n - 1; i >= 0; i--) {
            int fullSum = 0; 
            for(int k = 0; k < 3; k++) {
                if(i + k < n) {
                    fullSum += arr[i + k];
                    dp[i] = max(fullSum - (i + k + 1 < n ? dp[i + k + 1] : 0), dp[i]); 
                }
            }
        }
        if(dp[0] == 0) {
            return "Tie";
        } else if(dp[0] > 0) {
            return "Alice";
        }
        return "Bob";
    }
};
