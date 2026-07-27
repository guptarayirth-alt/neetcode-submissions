class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (i > farthest) return false;      // current index unreachable
            farthest = max(farthest, i + nums[i]); // update max reach
            if (farthest >= n - 1) return true;    // can already reach end
        }

        return true;
    }
};
