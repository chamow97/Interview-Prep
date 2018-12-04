class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector < vector <int> > answer;
        if(n < 3)
        {
            return answer;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++)
        {
            if(i == 0 || nums[i] > nums[i-1])
            {
                int j = i + 1;
                int k = n - 1;
                while(j < k)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> now;
                        now.push_back(nums[i]);
                        now.push_back(nums[j]);
                        now.push_back(nums[k]);
                        answer.push_back(now);
                        j++;
                        k--;
                        while(j < k && nums[j] == nums[j-1])
                        {
                            j++;
                        }
                        while(j < k && nums[k] == nums[k+1])
                        {
                            k--;
                        }
                    }
                    else if(nums[i] + nums[j] + nums[k] < 0)
                    {
                        j++;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
        }
        return answer;
    }
};