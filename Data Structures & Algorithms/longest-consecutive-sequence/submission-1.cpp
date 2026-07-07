class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> ar;
        int n=nums.size();
        for(int k=0;k<n;k++)
        {
            ar.push_back(nums[k]);
        }
        sort(ar.begin(),ar.end());
        int maxcount=1;
        int count=1;
        if(n==0)
    {
        return 0;
    }
        for(int i=1;i<n;i++)
        {
        
            if(ar[i]==ar[i-1]+1)
            {
                count++;
            }
            else if(ar[i]==ar[i-1])
            {
                continue;
            }
            else {
                if (count > maxcount) {
                    maxcount = count;
                }
                count=1;

        }
    }
    if (count > maxcount) {
            maxcount = count;
        }
    return maxcount;
    }
};
