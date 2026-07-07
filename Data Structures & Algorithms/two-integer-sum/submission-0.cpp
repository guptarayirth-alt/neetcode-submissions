class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Loop 1: Pick the first number
        for(int i = 0; i < n; i++) {
            
            // Loop 2: Pick the second number (start from i + 1 to avoid duplicates)
            for(int j = i + 1; j < n; j++) {
                
                // Check if they match the target
                if(nums[i] + nums[j] == target) {
                    return {i, j}; // Found it!
                }
            }
        }
        
        return {}; // Should not reach here
    }
};