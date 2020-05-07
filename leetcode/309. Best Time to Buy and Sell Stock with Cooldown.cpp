class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) {
            return 0;
        }
        int lastSellPrice = 0, currentSellPrice = 0, currBuyPrice = -prices[0];
        for(int i = 2; i <= prices.size(); i++) {
            int newBuyPrice = max(lastSellPrice - prices[i - 1], currBuyPrice);
            int newSellPrice = max(currBuyPrice + prices[i - 1], currentSellPrice);
            lastSellPrice = currentSellPrice;
            currentSellPrice = newSellPrice;
            currBuyPrice = newBuyPrice;
        }
        return currentSellPrice;
    }
};
