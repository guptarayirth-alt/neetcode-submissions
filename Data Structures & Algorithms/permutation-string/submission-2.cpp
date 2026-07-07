class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        sort(s1.begin(), s1.end());
        vector<char> v;
        int r = 0;
        int l = 0;
        int flag = 0;

        while (l < s2.size()) {
            while (v.size() < s1.size() && l < s2.size()) {
                v.push_back(s2[l]);
                l++;
            }
            vector<char> temp = v; 
            sort(temp.begin(), temp.end());
            int i = 0;
            for (const char &el : temp) {
                if (i < s1.size() && s1[i] == el) {
                    i++;
                }
            }
            if (i == s1.size()) {
                flag = 1;
                break;
            }
            for (auto it = v.begin(); it != v.end(); ++it) {
                if (*it == s2[r]) {
                    v.erase(it);
                    break;
                }
            }
            r++;
        }

        return flag == 1;
    }
};