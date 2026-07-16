#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // dp[i][j] = min operations to convert word1's first i chars into word2's first j chars
        // Sized (n+1) x (m+1) to naturally represent the "0 characters used" base cases
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: transforming word1[0..i-1] into an EMPTY string needs i deletions
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        // Base case: transforming an EMPTY string into word2[0..j-1] needs j insertions
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        // Fill the rest of the table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    // Characters already match -- no operation needed here,
                    // just inherit the cost of matching the smaller prefixes
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Characters differ -- try all three operations, take the cheapest,
                    // and add 1 for whichever operation we chose
                    int replaceCost = dp[i - 1][j - 1]; // fix the mismatch directly
                    int deleteCost  = dp[i - 1][j];      // remove word1's current character
                    int insertCost  = dp[i][j - 1];      // add a new character to word1

                    dp[i][j] = 1 + min({replaceCost, deleteCost, insertCost});
                }
            }
        }

        // dp[n][m] = answer for the FULL word1 -> FULL word2 transformation
        return dp[n][m];
    }
};
   
