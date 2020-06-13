class Solution {
public:
    bool solve(int i, vector<int> &dp, vector<int> &arr, vector<bool> &visited) {
        if(i < 0 || i >= arr.size()) {
            return false;
        }
        if(visited[i]) {
           return false; 
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        visited[i] = true;
        bool currVal = solve(i - arr[i], dp, arr, visited) || solve(i + arr[i], dp, arr, visited);
        visited[i] = false;
        dp[i] = currVal;
        return dp[i];
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n, -1);
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) {
                dp[i] = 1;
            }
        }
        return solve(start, dp, arr, visited);
    }
};
