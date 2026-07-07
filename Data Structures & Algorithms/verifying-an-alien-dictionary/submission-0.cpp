class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Step 1: Build the speed-lookup array. 
        // Using a fixed array of size 26 is faster than an unordered_map.
        int alienOrder[26];
        for (int i = 0; i < order.length(); i++) {
            // Convert character ('a'-'z') to an index (0-25)
            alienOrder[order[i] - 'a'] = i;
        }
        
        // Step 2: Compare adjacent pairs of words
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            
            bool foundMismatch = false;
            
            // Compare character by character up to the length of the shorter word
            int minLen = min(w1.length(), w2.length());
            for (int j = 0; j < minLen; j++) {
                
                // If characters are different, we found our decision point
                if (w1[j] != w2[j]) {
                    int char1Pos = alienOrder[w1[j] - 'a'];
                    int char2Pos = alienOrder[w2[j] - 'a'];
                    
                    // If the character in word1 comes AFTER word2's character, 
                    // the list is broken! Return false immediately.
                    if (char1Pos > char2Pos) {
                        return false;
                    }
                    
                    // If word1's character correctly comes before word2's character,
                    // this pair is perfectly sorted. Break out of the inner loop.
                    foundMismatch = true;
                    break; 
                }
            }
            
            // Step 3: Handle the prefix edge-case (e.g., "apple" vs "app")
            // If we checked all characters without finding a mismatch, it means
            // one word is a prefix of another. The shorter word MUST come first.
            if (!foundMismatch && w1.length() > w2.length()) {
                return false;
            }
        }
        
        // If we verified all adjacent pairs without hitting a violation, the list is sorted!
        return true;
    }
};