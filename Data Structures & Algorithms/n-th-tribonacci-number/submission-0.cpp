class Solution {
public:
    int tribonacci(int n) {
        // Handle small edge cases immediately to prevent out-of-bounds errors
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        // Create the DP table up to size n
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        // Start calculating from index 3 up to n
        for (int i = 3; i <= n; i++) {
            // The Tribonacci formula: sum of the last 3 elements
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
    }
};