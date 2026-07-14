class Solution {
public:
    int integerBreak(int n) {
        // Base cases: numbers less than 4 must be broken down, 
        // which unfortunately yields a product smaller than the number itself.
        if (n == 2) return 1; // 1 + 1 -> 1 * 1 = 1
        if (n == 3) return 2; // 1 + 2 -> 1 * 2 = 2

        // dp[i] will store the max product for number i
        std::vector<int> dp(n + 1, 0);
        
        // For numbers 2 and 3, if they are *pieces* of a larger number, 
        // it's better to NOT break them (e.g., a piece of 3 is better than 2*1).
        dp[1] = 1;
        dp[2] = 2; 
        dp[3] = 3; 

        // Build up the DP table
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                // dp[i] is the max of its current value, or cutting off 'j' 
                // and multiplying it by the optimal way to break 'i-j'
                dp[i] = std::max(dp[i], j * dp[i - j]);
            }
        }
        
        return dp[n];
    }
};