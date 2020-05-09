class Solution {
public:
    long long ans;
    void binarySearch(long long low, long long high, long long target) {
        if(low > high) {
            return;
        }
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if(val <= target) {
            ans = mid;
            low = mid + 1;
        } else if(val > target) {
            high = mid - 1;
        }
        binarySearch(low, high, target);
    }
    bool isPerfectSquare(int num) {
        ans = 0;
        binarySearch(0, num, num);
        return ((ans * ans) == num);
    }
};
