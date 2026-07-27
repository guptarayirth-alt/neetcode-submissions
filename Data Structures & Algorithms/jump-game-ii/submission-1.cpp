class Solution {
public:
    int jump(vector<int>& nums) {
        int sum = 0;    // farthest boundary reached so far
        int count = 0;
        int i = 0;
        int n = nums.size() - 1;

        while (sum < n) {
            int m = 0;
            for (int j = i; j <= sum; j++) {
                m = max(m, j + nums[j]);
            }
            i = sum + 1;
            sum = m;
            count++;
        }
        return count;
    }
};
