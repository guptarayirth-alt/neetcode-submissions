class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> map;
      for(int t : nums)
      {
         map[t]++;
         
      } 
      vector<pair<int, int>> freq;
      for(auto it : map)
      {
      freq.push_back({it.second, it.first});
      }
      vector<int> result;
      sort(freq.begin(), freq.end(), greater<pair<int, int>>());
       for(int i =0; i<k ; i++)
       {
         result.push_back(freq[i].second);
        
       } 
       return result;
    }
};
