class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        if (m == 0) return 0;

        // If the starting point or ending point is an obstacle, no paths exist.
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }

        // DP table initialized to 0
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Starting point
        dp[0][0] = 1;

        // Initialize the first column
        for (int i = 1; i < n; i++) {
            // A cell is reachable only if it's not an obstacle AND the cell above it is reachable
            if (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) {
                dp[i][0] = 1;
            }
        }

        // Initialize the first row
        for (int j = 1; j < m; j++) {
            // A cell is reachable only if it's not an obstacle AND the cell to its left is reachable
            if (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) {
                dp[0][j] = 1;
            }
        }

        // Fill the rest of the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0; // Obstacle means 0 paths can go through here
                }
            }
        }

        return dp[n-1][m-1];
    }
};