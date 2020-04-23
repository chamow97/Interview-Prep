class Solution {
public:
    int solve(int i, int m, map< pair<int, int>, int > &memo, vector<int> &suffix) {
        if(i >= suffix.size()) {
            return 0;
        }
        if(2 * m >= suffix.size() - i) {
            return suffix[i];
        }
        if(memo[{i, m}] != 0) {
            return memo[{i, m}];
        }
        int currMax = INT_MAX;
        for(int l = 1; l <= 2 * m; l++) {
            currMax = min(currMax, solve(i + l, max(l, m), memo, suffix));
        }
        memo[{i, m}] = suffix[i] - currMax;
        return memo[{i, m}];
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n, 0);
        suffix[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        map< pair<int, int>, int > memo;
        return solve(0, 1, memo, suffix);
    }
};
