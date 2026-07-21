 class Solution {
private:
    void good(vector<string> &final, string &curr, int open, int closed, int n)
    {
        if (curr.size() == 2 * n)
        {
            final.push_back(curr);
            return;
        }

        if (open < n)
        {
            curr.push_back('(');
            good(final, curr, open + 1, closed, n);
            curr.pop_back();
        }

        if (closed < open)
        {
            curr.push_back(')');
            good(final, curr, open, closed + 1, n);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> final;
        string curr;
        good(final, curr, 0, 0, n);
        return final;
    }
};
