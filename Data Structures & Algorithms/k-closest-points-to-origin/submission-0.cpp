class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq; // max-heap of {distance, index}
        int n = points.size();

        for (int i = 0; i < n; i++)
        {
            int distance = 0;
            distance = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            pq.push({distance, i});

            if (pq.size() > k)   // evict the farthest point once we exceed k
            {
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while (!pq.empty())      // drain whatever remains (the k closest points)
        {
            int idx = pq.top().second;
            result.push_back(points[idx]);
            pq.pop();
        }

        return result;
    }
};
