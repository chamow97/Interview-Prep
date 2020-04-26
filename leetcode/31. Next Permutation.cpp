class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Naryana Pandita hail! 
        // find the largest index where nums[k] < nums[k + 1]
        int index = -1;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] < nums[i + 1]) {
                index = i;
            }
        }
        //if cant find, reverse the array and stop
        if(index == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            // find last index l which is greater than k
            int largestNextIndex = index + 1;
            for(int i = index + 1; i < n; i++) {
                if(nums[i] > nums[index]) {
                    largestNextIndex = i;
                }
            }
            // swap the value of k and l
            swap(nums[index], nums[largestNextIndex]);
            // reverse from k + 1 .... n
            reverse(nums.begin() + index + 1, nums.end());
        }
    }
};
