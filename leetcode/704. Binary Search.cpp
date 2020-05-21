class Solution {
public:
    int index;
    void binarySearch(int low, int high, vector<int> &nums, int target) {
        if(low > high) {
            return;
        }
        int mid = (low + high) / 2;
        if(nums[mid] == target) {
            index = mid;
            return;
        }
        if(nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        binarySearch(low, high, nums, target);
    }
    int search(vector<int>& nums, int target) {
        index = -1;
        binarySearch(0, nums.size() - 1, nums, target);
        return index;
    }
};
