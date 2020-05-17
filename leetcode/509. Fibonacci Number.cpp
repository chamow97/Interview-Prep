class Solution {
public:
    int fib(int N) {
        N++;
        int a = -1, b = 1, c = 0;
        while(N--) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
