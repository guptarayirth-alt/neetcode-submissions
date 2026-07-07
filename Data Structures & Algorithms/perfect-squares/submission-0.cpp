class Solution {
public:
    int numSquares(int n) {
       
        vector<int> dp(n + 1, n + 1);
        
        dp[0] = 0;
      
        for (int i = 1; i <= n; i++) {
            for (int s = 1; s * s <= i; s++) {
                int square = s * s;
                dp[i] = min(dp[i], 1 + dp[i - square]);
            }
        }
        
        return dp[n];
    }
};