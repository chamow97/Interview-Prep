class Solution {
public:
    vector< vector<int> > result;
    void solve(int index, int target, vector<int> &candidates, vector<int> currAns) {
        if(target == 0) {
            result.push_back(currAns);
            return;
        }
        if(index >= candidates.size() || target < 0) {
            return;
        }
        int i = index;
        while(i < candidates.size() && target - candidates[i] >= 0) {
            if(i && candidates[i] == candidates[i - 1] && i > index) {
                i++;
                continue;
            }
            currAns.push_back(candidates[i]);
            solve(i + 1, target - candidates[i], candidates, currAns);
            currAns.pop_back();
            i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.resize(0);
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, vector<int>());
        return result;
    }
};
