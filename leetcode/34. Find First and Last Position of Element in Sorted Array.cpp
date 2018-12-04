class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        vector<int> answer;
        int n = nums.size();
        if(start >= 0 && start < n && nums[start] == target)
        {
            answer.push_back(start);
            int ending = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            ending--;
            answer.push_back(ending);
        }
        else
        {
            answer.push_back(-1);
            answer.push_back(-1);
        }
        return answer;
    }
};