class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count=0;
        int maxcount=0;
        set<char> st;
        int r=0;
        int l=0;
        while(l!= s.size())
        {
            if( st.count(s[l]) < 1)
            {
            st.insert(s[l]);
            l++;
            }
            else
            {
                st.erase(s[r]);
                r++;
            }
            
            count= st.size();
            maxcount= max( maxcount, count);
        }
        return maxcount;
        
    }
};
