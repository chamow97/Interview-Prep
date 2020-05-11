class Solution {
public:
    static bool myFunc(pair< pair<int, int>, int > a, pair< pair<int, int>, int > b) {
        if(a.first.second == b.first.second) {
            return a.first.first < b.first.first;
        }
        return a.first.second < b.first.second;
    }
    
    static bool myComp1(pair< pair<int, int>, int> a, pair< pair<int, int>, int> b) {
        return a.first.second < b.first.second;
    }
    
    int solve(vector< pair< pair<int, int>, int > > &adj, int index, vector<int> &dp) {
        if(index < 0) {
            return 0;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        int currStart = adj[index].first.first;
        int maxIndexWeCanTake = upper_bound(adj.begin(), adj.end(), make_pair(make_pair(0, currStart), 0), myComp1) - adj.begin();
        int currValue = max(solve(adj, index - 1, dp), adj[index].second + solve(adj, maxIndexWeCanTake - 1, dp));
        dp[index] = currValue;
        return currValue;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector< pair< pair<int, int>, int > > adj;
        for(int i = 0; i < startTime.size(); i++) {
            adj.push_back({{startTime[i], endTime[i]}, profit[i]});
        }
        sort(adj.begin(), adj.end(), myFunc);
        vector<int> dp(startTime.size(), -1);
        return solve(adj, startTime.size() - 1, dp);
    }
};
