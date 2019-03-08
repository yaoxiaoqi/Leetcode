class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyInPrice = INT_MAX;
        int profit = 0;
        for (auto price: prices) {
            if (price < buyInPrice) {
                buyInPrice = price;
            }
            if (price - buyInPrice > profit) {
                profit = price - buyInPrice;
            }
        }
        return profit;
    }
};
