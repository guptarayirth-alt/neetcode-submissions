class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // dp[i] will store the minimum cost to reach step i
        vector<int> dp(n + 1);
        
        // Base cases: Starting steps cost 0 to reach
        dp[0] = 0;
        dp[1] = 0;
        
        // Build the table from bottom to top
        for (int i = 2; i <= n; i++) {
            // Min cost to reach step i is the minimum of:
            // 1. Coming from i-1 and paying cost[i-1]
            // 2. Coming from i-2 and paying cost[i-2]
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        
        // The top of the floor is step n
        return dp[n];
    }
};
