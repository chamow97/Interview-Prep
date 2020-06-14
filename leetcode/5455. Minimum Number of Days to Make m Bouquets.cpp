class Solution {
public:
    int ans;
    void binarySearch(int low, int high, vector<int> &bloomDay, int m, int k) {
        if(low > high) {
            return;
        }
        int mid = (low + high) / 2;
        int successive = 0, currCount = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) {
                successive++;
            } else {
                successive = 0;
            }
            if(successive == k) {
                ++currCount;
                successive = 0;
            }
        }
        if(currCount >= m) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        binarySearch(low, high, bloomDay, m, k);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        ans = -1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        binarySearch(low, high, bloomDay, m, k);
        return ans;
    }
};
