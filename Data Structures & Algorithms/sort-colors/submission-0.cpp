class Solution {
public:
    void sortColors(vector<int>& nums) {
       map<int,int> mp;
       for(auto it: nums)
       {
        mp[it]++;
       } 
       int idx = 0;
        for (int color = 0; color < 3; color++) {
            while (mp[color] > 0) {
                nums[idx] = color;
                idx++;
                mp[color]--;
            }
        }
    }
};