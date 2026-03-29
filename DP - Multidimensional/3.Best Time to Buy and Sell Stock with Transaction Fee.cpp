class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int money = 0, hold = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            // buy
            hold = max(hold, money - prices[i]);
            // sell
            money = max(money, hold + prices[i] - fee);
        }
        return money;
    }
};

// I suggest reading this for different dp solution + greedy 
// https://algo.monster/liteproblems/714
