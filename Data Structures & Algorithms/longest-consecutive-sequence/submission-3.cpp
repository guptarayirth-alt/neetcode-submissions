class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }

        set<int> v;
        for (int i = 0; i < n; i++) {
            v.insert(nums[i]);
        }
        
        int count = 1;
        int maxcount = 1;
        
        auto it = v.begin();
        int prev = *it;
        it++;
        
        while (it != v.end()) {
            int current = *it;
            
            if (current == prev + 1) {
                count++;
            } 
            else {
                if (count > maxcount) {
                    maxcount = count;
                }
                count = 1;
            }
            
            prev = current;
            it++;
        }
        
        if (count > maxcount) {
            maxcount = count;
        }
        
        return maxcount;
    }
};