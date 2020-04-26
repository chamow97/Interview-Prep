class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // insanse problem, first xor all numbers
        // we will end up with a ^ b
        // now we need to find a and b
        // since a and b are distinct, there should be atleast 1 set bit
        // this means one of the number doesn't have that bit set and other has it
        // we divide the array into 2, now xor each part to get the 2 numbers insane
        
        int totalXor = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            totalXor ^= nums[i];
        }
        int xthSetBit = 0;
        int k = 0;
        while(xthSetBit == 0) {
            k++;
            xthSetBit = (1 << (k - 1)) & totalXor;
        }
        vector<int> with1AsSet;
        vector<int> with0AsSet;
        for(int i = 0; i < n; i++) {
            if(((1 << (k - 1)) & nums[i]) == 0) {
                with0AsSet.push_back(nums[i]);
            } else {
                with1AsSet.push_back(nums[i]);
            }
        }
        int firstNumber = 0, secondNumber = 0;
        for(int i = 0; i < with0AsSet.size(); i++) {
            firstNumber ^= with0AsSet[i];
        }
        for(int i = 0; i < with1AsSet.size(); i++) {
            secondNumber ^= with1AsSet[i];
        }
        vector<int> result;
        result.push_back(firstNumber);
        result.push_back(secondNumber);
        return result;
    }
};
