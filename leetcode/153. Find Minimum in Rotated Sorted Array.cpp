class Solution {
public:
    int answer;
    vector<int> arr;
    int n;
    void binarySeach(int low, int high) {
        if(high < low) {
            return;
        }
        int mid = (low + high) / 2;
        if(mid == 0) {
            answer = min(arr[mid], min(arr[high], answer));
            high = mid - 1;
        } else {
            if(arr[mid] > arr[mid - 1]) {
                if(arr[n - 1] < arr[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                answer = min(arr[mid], answer);
                low = mid + 1;
                high = mid - 1;
            }
        }
        binarySeach(low, high);
    } 
    int findMin(vector<int>& nums) {
        arr = nums;
        answer = INT_MAX;
        n = nums.size();
        binarySeach(0, n - 1);
        return answer;
    }
};
