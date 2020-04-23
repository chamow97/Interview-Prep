class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // find the common prefix of n, m
        // as simple as that, how do you find? right shift by one place till m == n
        if(m == 0) {
            return 0;
        }
        int numberOfShifts = 1;
        while(m != n) {
            m >>= 1;
            n >>= 1;
            numberOfShifts <<= 1;
        }
        return m * numberOfShifts;
    }
};
