class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // min-heap: {elevation, row, col} — always explore the lowest elevation frontier cell first
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // up, down, left, right
        int ans = 0;

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int elevation = top[0];
            int row = top[1];
            int col = top[2];

            // the time needed is the max elevation encountered so far on the best path
            ans = max(ans, elevation);

            if (row == n - 1 && col == n - 1)
            {
                return ans;
            }

            for (auto &dir : directions)
            {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !visited[newRow][newCol])
                {
                    visited[newRow][newCol] = true;
                    pq.push({grid[newRow][newCol], newRow, newCol});
                }
            }
        }

        return ans; // should always return inside the loop for a valid grid, this is a fallback
    }
};