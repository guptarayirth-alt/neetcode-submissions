 class Solution {
public:
 vector<int> twoSum(vector<int>& nums, int target)
     {
        map <int, int> rt;
        for(int i =0; i< nums.size();i++)
        {
            int current=nums[i];
            int needed = target- current;
            if(rt.find(needed)!=rt.end())
            {
                return {rt[needed],i};
            }
            rt[current]=i;
        }
        return {};
    }
 };