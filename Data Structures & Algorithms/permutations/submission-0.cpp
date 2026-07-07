class Solution {
public:
    void solve(vector<int>& nums, int index,  vector<vector<int>> &ans) {
        int n = nums.size();
        if(index==n)
        {
            ans.push_back(nums);
            return;
        }
  for (int i = index; i < n; i++) {
            swap(nums[index], nums[i]);
            solve(nums, index + 1, ans);
            swap(nums[index], nums[i]); // backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
         vector<vector<int>> ans;
        vector<int> arr;
        solve(nums, 0, ans);
        return ans;
    }
};
