class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> p;
       for (auto it: nums)
        {
            if(p.count(it))
            return it;
            else
            {
                p.insert(it);
            }
        }
        return -1;
    }
};
