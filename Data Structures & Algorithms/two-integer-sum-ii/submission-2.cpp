class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int currentSum = numbers[left] + numbers[right];

            if (currentSum == target) {
                return {left + 1, right + 1}; // Return 1-based indices
            } else if (currentSum < target) {
                left++; // Sum too small, move left pointer right
            } else {
                right--; // Sum too large, move right pointer left
            }
        }
        return {}; 
    }
};
