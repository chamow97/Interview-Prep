class Solution {
public:
    vector< vector<int> > result;
    void solve(int start, int n, int k, vector<int> curr) {
        if(start > n + 1 || curr.size() > k) {
            return;
        }
        if(curr.size() == k) {
            result.push_back(curr);
            return;
        }
        for(int i = start; i <= n; i++) {
            curr.push_back(i);
            solve(i + 1, n, k, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        solve(1, n, k, vector<int>(0));
        return result;
    }
};
