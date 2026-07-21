class Solution {
private:
    void repeatcomb(vector<int> &candidates, int target, int ind,
                     vector<int> &curr, int sum, vector<vector<int>> &result)
    {
        // dead ends
        if (sum > target || ind == candidates.size())
        {
            return;
        }

        // found a valid combination
        if (sum == target)
        {
            result.push_back(curr);
            return;
        }

        // include candidates[ind] again (stay on same index — reuse allowed)
        curr.push_back(candidates[ind]);
        repeatcomb(candidates, target, ind, curr, sum + candidates[ind], result);
        curr.pop_back();

        // exclude candidates[ind] entirely (move to next index)
        repeatcomb(candidates, target, ind + 1, curr, sum, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> curr;
        repeatcomb(candidates, target, 0, curr, 0, result);
        return result;
    }
};