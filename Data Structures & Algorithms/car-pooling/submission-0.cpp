class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<int, vector<int>,greater<int>> pq;
        int n = trips.size();
        std::sort(trips.begin(), trips.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1]; // Use '<' for ascending order
    });
        for(int i =0 ; i< n; i++)
        {
          if(trips[i][0]> capacity)
          {
            return false;
          }
          else if(pq.empty())
          {
            pq.push(trips[i][2]);
          }
          else
          {
            if(pq.top()> trips[i][1])
            {
              return false;
            }
            else
            {
              pq.push(trips[i][1]);
            }
          }
     
       }
       return true; 
    }
};