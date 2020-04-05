class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        // if you can sell today, we can get more profit by selling on some day after this
        // where the price is much more than this but if the price is less than this, then
        // its better to sell it today and deal with that stock as different due to the below proof
        // lets say we have a sequence, x, x + a, x + b, x + c, x + a, x + d
        // here d > c > b > a, here we have 2 choices, buy when price is x and
        // 1. sell when price is x + c and again buy x + a and sell at  x + d
        // 2. sell at x + d
        // for 1. profit is, (x + c - x - a) + (d - a);
        // for 2. profit is (d - a)
        // since c > a, 1. has better value than 2.
        // hence select increaing subarray and keep adding the difference of max and min in them
        // this is the best approach to maximize
        int i = 1;
        if(n == 0) {
            return 0;
        }
        int ans = 0;
        int minVal = arr[0];
        int maxVal = arr[0];
        while(i < n) {
            if(arr[i] > arr[i - 1]) {
                minVal = min(minVal, arr[i]);
                maxVal = max(maxVal, arr[i]);
                i++;
            } else {
                ans += (maxVal - minVal);
                minVal = arr[i];
                maxVal = arr[i];
                i++;
            }
        }
        ans += (maxVal - minVal);
        return ans;
    }
};
