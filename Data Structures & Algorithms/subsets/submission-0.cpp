class Solution {
public:
    void solve(vector<int>& nums, vector<int>& arr, int ind, vector<vector<int>>& ans) {
        int n = nums.size();
        if (ind == n) {
            ans.push_back(arr);
            return;
        }

        solve(nums, arr, ind + 1, ans);

        arr.push_back(nums[ind]);
        solve(nums, arr, ind + 1, ans);
        arr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(nums, arr, 0, ans);
        return ans;
    }
};