class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        while(k>0)
        {
           int x = nums[n-1];
           int left= n-2;
           int right= n-1;
           while(left >= 0)
           {
           nums[right] = nums[left];   
                right--;
                left--;
           }
           nums[0]=x;
           k--;
        }
    
    }
};