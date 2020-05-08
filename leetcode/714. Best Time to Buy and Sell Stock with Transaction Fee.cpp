class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n == 0) {
            return 0;
        }
        int currBuy = -prices[0];
        int currSell = 0;
        for(int i = 2; i <= n; i++) {
            int nextBuy = max(currSell - prices[i - 1], currBuy);
            int nextSell = max(currBuy - fee + prices[i - 1], currSell);
            currSell = nextSell;
            currBuy = nextBuy;
        }
        return currSell;
    }
};
