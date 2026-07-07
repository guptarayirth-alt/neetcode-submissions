class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=1;
        int pro=0;
        int maxpro=0;
        int n= prices.size();
        while(r!=n)
        {
           if (prices[l] < prices[r]) {
                int pro = prices[r] - prices[l];
                maxpro = max(maxpro, pro);
            } else {
                l = r;
            }
            r++;
        }
    
        return maxpro;
        
    }
};
