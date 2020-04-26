class Solution {
public:
    void solve(int begin, vector<int> &nums, vector< vector<int> > &result, vector<int> curr) {
        if(begin >= nums.size()) {
            return;
        }
        for(int i = begin; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            result.push_back(curr);
            solve(i + 1, nums, result, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > result;
        solve(0, nums, result, vector<int>(0));
        result.push_back(vector<int>(0));
        return result;
    }
};
