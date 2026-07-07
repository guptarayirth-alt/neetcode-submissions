class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> st;
        vector<int> vc;
        for(int &c : nums)
        {
            st[c]++;
         }
        for(auto &pair : st) { 
            int number = pair.first;
            int count = pair.second;
            while(count > 0) {
                vc.push_back(number);
                count--;
            }
        }
        return vc;
        
    }
};