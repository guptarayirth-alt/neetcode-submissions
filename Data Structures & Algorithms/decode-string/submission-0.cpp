class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (s[i] != ']')
            {
                st.push(string(1, s[i]));
            }
            else
            {
                string decoded = "";
                while (st.top() != "[")
                {
                    decoded = st.top() + decoded;
                    st.pop();
                }
                st.pop();

                string numStr = "";
                while (!st.empty() && isdigit(st.top()[0]))
                {
                    numStr = st.top() + numStr;
                    st.pop();
                }

                int num = stoi(numStr);
                string repeated = "";
                while (num != 0)
                {
                    repeated += decoded;
                    num--;
                }

                st.push(repeated);
            }
        }

        string result = "";
        vector<string> parts;
        while (!st.empty())
        {
            parts.push_back(st.top());
            st.pop();
        }
        for (int i = parts.size() - 1; i >= 0; i--)
        {
            result += parts[i];
        }
        return result;
    }
};