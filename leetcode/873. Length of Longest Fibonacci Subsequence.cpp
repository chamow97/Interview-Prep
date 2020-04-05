class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        vector< vector<int> > dp(n, vector<int>(n, 2));
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[A[i]] = i;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int need = A[i] - A[j];
                if(m.find(need) != m.end()) {
                    if(m[need] < j) {
                        dp[j][i] = max(dp[j][i], 1 + dp[m[need]][j]);   
                    }
                }
            }
        }
        int maximum = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                maximum = max(maximum, dp[j][i]);
            }
        }
        if(maximum == 2) {
            maximum = 0;
        }
        return maximum;
    }
};
