int maxProfit(vector<int>& prices) {
    int profit = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        int d = prices[i] - prices[i-1];
        if(d > 0)
            profit += d;
    }
    return profit;
}
