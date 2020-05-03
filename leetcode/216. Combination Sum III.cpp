class Solution {
public:
    vector< vector<int> > ans;
    void solve(int currSize, int sum, int k, vector<int> &curr) {
        if(sum < 0) {
            return;
        }
        if(currSize > k) {
            return;
        }
        if(currSize == k && sum == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i = curr.size() == 0 ? 1 : curr.back() + 1; i <= 9; i++) {
            if(find(curr.begin(), curr.end(), i) != curr.end()) {
                continue;
            }
            curr.push_back(i);
            solve(currSize + 1, sum - i, k, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.resize(0);
        vector<int> curr;
        solve(0, n, k, curr);
        return ans;
    }
};
