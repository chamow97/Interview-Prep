class Solution {
public:
    int index;
    void binarySearch(vector<int> &nums, int low, int high, int target) {
        if(low > high) {
            return;
        }
        int mid = (low + high) / 2;
        cout << low << ' ' << mid << ' ' << high << '\n';
        if(nums[mid] == target) {
            index = mid;
            return;
        } 
        if(nums[mid] > nums[high]) {
            if(target < nums[mid] && target >= nums[low]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else if(nums[mid] < nums[low]) {
            if(target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } else if(nums[mid] == nums[low] && nums[mid] == nums[high]) {
            low++;
            high--;
        }else {
            if(target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        binarySearch(nums, low, high, target);     
    }
    int search(vector<int>& nums, int target) {
        index = -1;
        int n = nums.size();
        binarySearch(nums, 0, n - 1, target);
        return index != -1;
    }
};
