class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        stack<int> st;
        int n = operations.size();

        for (int i = 0; i < n; i++)
        {
            if (operations[i] == "+")
            {
                int k = st.top();
                st.pop();
                int a = st.top();
                st.push(k);
                a = a + k;
                st.push(a);
            }
            else if (operations[i] == "C")
            {
                st.pop();
            }
            else if (operations[i] == "D")
            {
                int k = st.top();
                st.push(k * 2);
            }
            else
            {
                st.push(stoi(operations[i]));
            }
        }

        while (!st.empty())
        {
            sum = sum + st.top();
            st.pop();
        }

        return sum;
    }
};