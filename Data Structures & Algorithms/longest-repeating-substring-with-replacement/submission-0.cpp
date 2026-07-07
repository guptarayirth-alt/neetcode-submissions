class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int l = 0;
        int max_f = 0;
        int result = 0;

        for (int r = 0; r < s.size(); r++) {
            counts[s[r]]++;
            max_f = max(max_f, counts[s[r]]);

            while ((r - l + 1) - max_f > k) {
                counts[s[l]]--;
                l++;
            }

            result = max(result, r - l + 1);
        }

        return result;
    }
};