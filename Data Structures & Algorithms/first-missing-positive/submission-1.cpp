class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for( auto it :  nums)
        {
            st.insert(it);
        }
        for(int i = 1;i< n+1; i++ )
        {
          
            if(st.find(i) == st.end()) { 
                return i;
            }
        }

    }
};