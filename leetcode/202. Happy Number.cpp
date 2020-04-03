class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while(n) {
            int temp = n % 10;
            n /= 10;
            sum += (temp * temp); 
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);
        } while(slow != fast);
        return slow == 1;
    }
};
