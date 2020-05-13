class Solution {
public:
    int numberOfSteps (int num) {
        if(num == 0) {
            return 0;
        }
        int result = 0;
        while(num) {
            if(num % 2 == 0) {
                result += 1;
            } else {
                result += 2;
            }
            num /= 2;
        }
        return result - 1;
    }
};
