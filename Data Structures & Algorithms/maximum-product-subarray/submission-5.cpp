class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            
            // Before overwriting, save maxEndingHere since minEndingHere
            // calculation below also needs the OLD maxEndingHere
            int candidates_max = max({curr, maxEndingHere * curr, minEndingHere * curr});
            int candidates_min = min({curr, maxEndingHere * curr, minEndingHere * curr});
            
            maxEndingHere = candidates_max;
            minEndingHere = candidates_min;
            
            result = max(result, maxEndingHere);
        }
        
        return result;
    }
};