class Solution {
public:
    int ans;
    int minDiff;
    void binarySearch(int low, int high, vector<int> &arr, int target) {
        if(low > high) {
            return;
        }
        int mid = (low + high) / 2;
        int currVal = 0;
        for(auto i : arr) {
            currVal += min(mid, i);
        }
        if(minDiff > abs(currVal - target)) {
            ans = mid;
            minDiff = abs(currVal - target);
        }
        if(currVal > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        binarySearch(low, high, arr, target);
    }
    int findBestValue(vector<int>& arr, int target) {
        if(target <= arr.size()) {
            return 0;
        }
        ans = 0;
        minDiff = INT_MAX;
        binarySearch(1, *max_element(arr.begin(), arr.end()), arr, target);
        return ans;
    }
};
