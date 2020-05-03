class Solution {
public:
    void computeAnswer(vector<string> &ans, int start, int end, int startNum, int endNum) {
        if(start == end) {
            ans.push_back(to_string(startNum));
        } else {
            ans.push_back(to_string(startNum) + "->" + to_string(endNum));
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) {
            return {};
        }
        vector<string> ans;
        string curr = to_string(nums[0]);
        int i = 1;
        int start = 0, end = 0;
        while(i < nums.size()) {
            while(i < nums.size() && nums[i] == nums[i - 1] + 1) {
                end = i;
                i++;
            }
            computeAnswer(ans, start, end, nums[start], nums[end]);
            start = end + 1;
            end = start;
            i++;
        }
        if(start < nums.size() && end < nums.size()) {
            computeAnswer(ans, start, end, nums[start], nums[end]);
        }
        return ans;
    }
};
