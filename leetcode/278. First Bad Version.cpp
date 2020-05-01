// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersionNumber;
    void binarySearch(int low, int high) {
        if(low > high) {
            return;
        }
        int mid = low + (high - low) / 2;
        if(isBadVersion(mid)) {
            firstBadVersionNumber = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        binarySearch(low, high);
    }
    int firstBadVersion(int n) {
        firstBadVersionNumber = -1;
        binarySearch(1, n);
        return firstBadVersionNumber;
    }
};
