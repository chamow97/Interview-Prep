class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;
        while(right - left - 1 < k) {
            if(left >= 0 && right < n) {
                if(abs(x - arr[left]) <= abs(x - arr[right])) {
                    left--;
                } else {
                    right++;
                }
            }
            else if(left < 0) {
                right++;
            } else if(right >= n) {
                left--;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + min(n, right));
    }
};
