class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
    stack < int> max;
    int n = temperatures.size() ;
     vector<int> v(n,0);
    for(int i = 0; i < n; i++)
    {
       
            while (!max.empty() && temperatures[i] > temperatures[max.top()])
            {
                int index = max.top();
                max.pop();
                v[index] = i- index;
                
                            }
                            max.push(i);

    }
    return v;
    }
};
