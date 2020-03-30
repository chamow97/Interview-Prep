class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 1) {
            return 0;
        }
        int maxPrice = 0, minPrice = prices[0];
        for(int i = 0; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            maxPrice = max(maxPrice, prices[i] - minPrice);
        }
        return maxPrice;
    }
};
