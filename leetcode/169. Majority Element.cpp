class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // since majority element always exist
        // no need to check Moore's Voting Algorithm
        int majority = 0, count = 0;
        for(int i : nums) {
            if(count == 0) {
                majority = i;
            }
            count += (i != majority ? -1 : 1);
        }
        return majority;
    }
};
