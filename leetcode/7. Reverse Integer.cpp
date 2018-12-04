class Solution {
public:
    int reverse(int x) {
        bool isNegative = false;
        if(x < 0)
        {
            isNegative = true;
            x = abs(x);
        }
        long int sum = 0;
        while(x)
        {
            sum = (sum * 10) + (x % 10);
            x /= 10;
        }
        if(isNegative)
        {
            sum = -sum;
        }
        int curr = sum;
        if(curr != sum)
        {
            return 0;
        }
        return sum;
    }
};