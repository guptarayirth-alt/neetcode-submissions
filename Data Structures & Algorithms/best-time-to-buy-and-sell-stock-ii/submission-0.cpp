class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> v;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            v.push_back(prices[i]);
        }
        int max=0;
        
        for(int i=1;i<n;i++)
        {
            if(v[i] > v[i-1])
            {
                max += v[i] - v[i-1];
            }
        }

        return max;  
    }
};