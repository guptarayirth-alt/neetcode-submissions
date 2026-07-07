class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        
        // dp[i] represents whether s[i...n-1] can be segmented into dictionary words
        vector<bool> dp(n + 1, false);
        
        // Base case: reaching the end of the string is a successful segmentation
        dp[n] = true; 
        
        // Loop backwards starting from the last character
        for (int i = n - 1; i >= 0; i--) {
            for (const string& w : wordDict) {
                int wordLen = w.length();
                
                // 1. Check if the word fits within the remaining bounds of 's'
                // 2. Check if the substring starting at 'i' matches the word 'w'
                //    s.compare(start_pos, length, string_to_compare) == 0 means an exact match
                if (i + wordLen <= n && s.compare(i, wordLen, w) == 0) {
                    
                    // If it matches, index i inherits the validity of the string AFTER the word
                    dp[i] = dp[i + wordLen];
                }
                
                // If we found a valid segmentation path from index i, stop checking other words
                if (dp[i]) {
                    break;
                }
            }
        }
        
        // The answer for the entire string evaluates at index 0
        return dp[0];
    }
};