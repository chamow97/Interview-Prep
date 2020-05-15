class Solution {
public:
    static bool myFunc(int a, int b) {
        int aC = __builtin_popcount(a);
        int bC = __builtin_popcount(b);
        if(aC == bC) {
            return a < b;
        }
        return aC < bC;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), myFunc);
        return arr;
    }
};
