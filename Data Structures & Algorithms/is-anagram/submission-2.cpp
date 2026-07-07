class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length())
        return false;
        unordered_map<char,int> rt;
        for(char c:s)
        {
          rt[c]++;  
        }
        for(char c:t)
        {
            if(rt.find(c)==rt.end()||rt[c]==0)
            {
                return false;
            }
            rt[c]--;
        }
        
        return true;
    }
};
