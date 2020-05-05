class Solution {
public:
    int bitwiseComplement(int num) {
        // find the bitwise XOR of num and 2^(numOfBits of num) - 1
        if(num == 0) {
            return 1;
        }
        int numberOfBits = log2(num) + 1;
        int powerNumber = pow(2, numberOfBits) - 1;
        return num ^ powerNumber;
    }
};
