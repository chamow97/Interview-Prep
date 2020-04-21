class Solution {
public:
    int n;
    vector< vector< int > > dp;
    vector< vector< bool > > seen;
    int solve(int index, int multiplier, vector<int> &satisfaction) {
        if(index >= n || multiplier > n) {
            return 0;
        }
        if(seen[index][multiplier]) {
            return dp[index][multiplier];
        }
        int currVal = max(0 + solve(index + 1, multiplier, satisfaction), (satisfaction[index] * multiplier) + solve(index + 1, multiplier + 1, satisfaction));
        seen[index][multiplier] = true;
        dp[index][multiplier] = currVal;
        return currVal;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        // 0 - 1 Knapsack, uncomment other 3 lines for O(n^2) soln
        // dp.resize(n + 1, vector<int>(n + 1, 0));
        // seen.resize(n + 1, vector<bool> (n + 1, false));
        // return solve(0, 1, satisfaction);
        
        // Better solution greedy one
        int total = 0, res = 0;
        for(int i = n - 1; i >= 0 && satisfaction[i] > -total; i--) {
            total += satisfaction[i];
            res += total;
        }
        return res;
    }
};
