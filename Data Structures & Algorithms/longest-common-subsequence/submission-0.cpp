class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        // DP table of size (n + 1) x (m + 1) initialized to 0
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Since strings are 0-indexed, we check i-1 and j-1
                if (text1[i - 1] == text2[j - 1]) {
                    // Match found: take diagonal value + 1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // No match: take maximum from top or left
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];  
    }
};