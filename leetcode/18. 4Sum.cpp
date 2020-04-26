class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 4) {
            return vector< vector<int> >(0);
        }
        vector< vector<int> > ans;
        int currSum = nums[0] + nums[1] + nums[2] + nums[3];
        for(int i = 0; i < n - 3; i++) {
            if(i && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1, l = n - 1;
                while(k < l) {
                    if(k > j + 1 && nums[k] == nums[k - 1]) {
                        k++;
                        continue;
                    }
                    int currSum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(currSum == target) {
                        vector<int> curr;
                        curr.push_back(nums[i]);
                        curr.push_back(nums[j]);
                        curr.push_back(nums[k]);
                        curr.push_back(nums[l]);
                        ans.push_back(curr);
                        k++;
                    } else if(currSum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
