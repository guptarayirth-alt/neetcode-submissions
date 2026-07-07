class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int s : nums)
        sum = sum + s;
        if( sum %2)
        {
            return false;
        }
        else{
            int target = sum /2;
            vector< bool> dp(target+1, false);
            dp[0]= true;
            for(int num: nums)
            {
            for(int i = target; i>= num; i--){
                dp[i]= dp[i]|| dp[i - num];
            }
            }
            return dp[target];
        }
        
    }
};
