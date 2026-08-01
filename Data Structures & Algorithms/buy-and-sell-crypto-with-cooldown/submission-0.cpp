class Solution {
    int getAns(vector<int> prices, int ind, int buy, int n, vector<vector<int>> &dp) {
    // Base case: If we've reached the end of the array, return 0 profit.
    if (ind >= n) return 0;
    
    // Check if the result is already computed
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
        
    int profit;
    
    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(prices, ind + 1, 0, n, dp), -prices[ind] + getAns(prices, ind + 1, 1, n, dp));
    }
    
    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(prices, ind + 1, 1, n, dp), prices[ind] + getAns(prices, ind + 2, 0, n, dp));
    }
    
    // Store the result in the DP array and return
    return dp[ind][buy] = profit;
}
public:
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    
    int ans = getAns(prices, 0, 0, n, dp);
    return ans;

    }
};
