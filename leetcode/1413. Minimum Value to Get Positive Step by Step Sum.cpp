class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sumHere = 0;
        int minVal = 1;
        for(int i = 0; i < nums.size(); i++) {
            sumHere += nums[i];
            if(sumHere <= 0) {
                minVal = max(minVal, abs(sumHere) + 1);
            }
        }
        return minVal;
    }
};
