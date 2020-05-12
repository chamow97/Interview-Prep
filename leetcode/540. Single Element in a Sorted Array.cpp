class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1, mid;
        while(low < high) {
            mid = low + (high - low) / 2;
            
            if(mid % 2 == 0) {
                if(mid > 0 && arr[mid] == arr[mid - 1]) {
                    high = mid - 2;
                } else if(mid < n - 1 && arr[mid] == arr[mid + 1]) {
                    low = mid + 2;
                } else {
                    return arr[mid];
                }
            } else {
                if(mid > 0 && arr[mid] == arr[mid - 1]) {
                    low = mid + 1;
                } else if(mid < n - 1 && arr[mid] == arr[mid + 1]) {
                    high = mid - 1;
                } else {
                    return arr[mid];
                }
            }
        }
        return arr[low];
    }
};
