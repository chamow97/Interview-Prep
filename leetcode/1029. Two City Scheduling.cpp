class Solution {
public:
    static bool myFunc(vector<int> &a, vector<int> &b) {
        return (a[0] - a[1]) < (b[0] - b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0;
        sort(costs.begin(), costs.end(), myFunc);
        for(int i = 0; i < costs.size() / 2; i++) {
            ans += costs[i][0];
        }
        for(int i = costs.size() / 2; i < costs.size(); i++) {
            ans += costs[i][1];
        }
        return ans;
    }
};
