class Solution {
public:
    int n;
    vector<int> candidate;
    vector< vector<int> > answerSet;
    void solve(vector<int> curr, int sum, int index)
    {
        if(sum < 0)
        {
            return;
        }
        if(sum == 0)
        {
            answerSet.push_back(curr);
            return;
        }
        while(index < n && sum - candidate[index] >= 0)
        {
            curr.push_back(candidate[index]);
            solve(curr, sum - candidate[index], index);
            index++;
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candidate = candidates;
        n = candidates.size();
        vector<int> curr;
        solve(curr, target, 0);
        return answerSet;
    }
};