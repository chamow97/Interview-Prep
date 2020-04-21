/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int index;
    void getVal(int low, int high, BinaryMatrix &binaryMatrix, int i) {
        if(low > high) {
            return;
        }
        int mid = (low + high) / 2;
        if(binaryMatrix.get(i, mid) == 1) {
            index = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        getVal(low, high, binaryMatrix, i);
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int n = dim[0];
        int m = dim[1];
        vector<int> freq(m, 0);
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            index = -1;
            getVal(0, m - 1, binaryMatrix, i);
            if(index != -1) {
                ans = min(ans, index);
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};
