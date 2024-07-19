class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0] , profit = 0;

        for(auto price: prices){
            buyPrice = min(buyPrice, price);
            int p = price - buyPrice;
            if(profit < p){
                profit = p;
            }
        }

        return profit;
    }
};
