class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int c : asteroids)
        {
            if (c > 0)
            {
                st.push(c);
            }
            else
            {
                while (!st.empty() && st.top() > 0 && st.top() < -c)
                {
                    st.pop();
                }

                if (st.empty() || st.top() < 0)
                {
                    st.push(c);
                }
                else if (st.top() == -c)
                {
                    st.pop();
                }
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--)
        {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};