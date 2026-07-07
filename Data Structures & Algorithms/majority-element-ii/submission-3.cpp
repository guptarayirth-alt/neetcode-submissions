class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> v;
        int n = nums.size();
        for(int t:nums)
        {
            v[t]++;
        }
        vector<int>result;
        for(auto it : v)
        {
            if(it.second> n/3)
            {
                result.push_back(it.first);
            }
           
        }
            
        return result;
        
    }
};