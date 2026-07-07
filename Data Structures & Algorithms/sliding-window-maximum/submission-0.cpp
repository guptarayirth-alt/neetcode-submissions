class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        vector<int> z;
        int r=0;
        int l=0;
        while(l <= nums.size())
        {
            while(l-r < k && l < nums.size())
            {
                v.push_back(nums[l]);
                l++;
            }
            if (v.size() < k) break;
            vector<int> temp = v;
            sort(temp.begin(), temp.end());
            z.push_back(temp[k-1]);
            v.erase(v.begin());
            r++;
        }
        return z;
    }
};