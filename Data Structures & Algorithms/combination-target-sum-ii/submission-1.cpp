class Solution {
public:
    void sums(vector<int>& nums, vector<int>& arr, int index, vector<vector<int>>& subs, int target) {
        int n = nums.size();
        
        if (target == 0) {
            subs.push_back(arr);
            return;
        }
        if (index == n || target < 0) {
            return;
        }

        int next_index = index + 1;
        while (next_index < n && nums[next_index] == nums[index]) {
            next_index++;
        }
        sums(nums, arr, next_index, subs, target);

        arr.push_back(nums[index]);
        sums(nums, arr, index + 1, subs, target - nums[index]);
        arr.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> arr;
        sums(nums, arr, 0, subs, target);
        return subs;
    }
};
