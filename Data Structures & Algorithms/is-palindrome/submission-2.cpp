class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for(char c : s)
        {
            if(isalnum(c))
            filtered+= tolower(c);
        }
        int n = filtered.length();
        for(int i =0; i < n/2 ; i ++)
        {
          string left, right;
          left= filtered[i];
          right= filtered[n-1-i];
          if(left == right )
          {
            continue;
          }
          else
          {
            return false;
            break;
          }
        }
        return true;
        
    }
};
