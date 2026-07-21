class Solution {
private:
    void solve(vector<int> &nums, vector<int> &curr, vector<bool> &used,
               vector<vector<int>> &result)
    {
        if (curr.size() == nums.size())
        {
            result.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // skip if already used in this permutation
            if (used[i])
            {
                continue;
            }

            // skip duplicates: if this value equals the previous one,
            // and the previous one is NOT currently used (meaning we already
            // fully explored placing it here and backtracked), skip this copy too
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            {
                continue;
            }

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums, curr, used, result);

            curr.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        solve(nums, curr, used, result);
        return result;
    }
};