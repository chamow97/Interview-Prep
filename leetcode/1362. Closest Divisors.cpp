class Solution {
public:
    int div1;
    int div2;
    int minDiff;
    void compute(int num) {     
        for(int i = 1; i <= sqrt(num); i++) {
            if(num % i == 0) {
                int absD = abs(i - (num / i));
                if(minDiff > absD) {
                    minDiff = absD;
                    div1 = i;
                    div2 = num / i;
                }
            }
        }
    }
    vector<int> closestDivisors(int num) {
        minDiff = INT_MAX;
        div1 = 0;
        div2 = 0;
        compute(num + 1);
        compute(num + 2);
        return {div1, div2};
    }
};
