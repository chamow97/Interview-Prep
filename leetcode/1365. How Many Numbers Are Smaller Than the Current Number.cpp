class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector< int > count(101, 0);
        for(auto i : nums) {
            count[i]++;
        }
        for(int i = 1; i <= 100; i++) {
            count[i] += count[i - 1];
        }
        vector<int> ans;
        for(auto i : nums) {
            if(i == 0) {
                ans.push_back(0);
            }
            else ans.push_back(count[i - 1]);
        }
        return ans;
    }
};
