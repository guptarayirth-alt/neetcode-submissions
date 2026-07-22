class Solution {
private:
    bool repeate(vector<int> &matchsticks, vector<bool> &used, int side,
                 int sidesFormed, int curr, int ind)
    {
        // all 4 sides successfully formed
        if (sidesFormed == 4)
        {
            return true;
        }

        // current side is complete — start building the next side from scratch
        if (curr == side)
        {
            return repeate(matchsticks, used, side, sidesFormed + 1, 0, 0);
        }

        // try every matchstick for the current side
        for (int i = ind; i < matchsticks.size(); i++)
        {
            if (used[i] || curr + matchsticks[i] > side)
            {
                continue; // skip already-used sticks, or ones that would overshoot
            }

            used[i] = true;
            if (repeate(matchsticks, used, side, sidesFormed, curr + matchsticks[i], i + 1))
            {
                return true;
            }
            used[i] = false; // backtrack
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += matchsticks[i];
        }

        if (n < 4 || sum % 4 != 0)
        {
            return false;
        }

        int side = sum / 4;
        vector<bool> used(n, false);
        return repeate(matchsticks, used, side, 0, 0, 0);
    }
};