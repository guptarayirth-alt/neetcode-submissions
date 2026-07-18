class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        // Min-heap to explore the path with the minimum "maximum effort" first.
        // Stores vectors of format: {current_max_effort, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Tracks the minimum effort required to reach each cell. Initialize to INT_MAX.
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        
        // 4-directional movement: right, left, down, up
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Start at the top-left cell
        pq.push({0, 0, 0});
        effort[0][0] = 0;
        
        while (!pq.empty()) {
            // Pop the cell with the lowest effort
            auto curr = pq.top();
            pq.pop();
            
            int current_effort = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            // Because we use a Min-Heap, the very first time we pop the destination 
            // cell, we are mathematically guaranteed it is the absolute minimum effort.
            if (r == rows - 1 && c == cols - 1) {
                return current_effort;
            }
            
            // Optimization: Skip stale entries in the priority queue
            if (current_effort > effort[r][c]) {
                continue;
            }
            
            // Explore all 4 valid neighbors
            for (const auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                // Ensure the neighbor is within grid bounds
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    
                    // The bottleneck is either the highest step we've taken so far, 
                    // or the step we are about to take right now.
                    int step_effort = abs(heights[r][c] - heights[nr][nc]);
                    int next_effort = max(current_effort, step_effort);
                    
                    // If we found a smoother route to this neighbor, update it
                    if (next_effort < effort[nr][nc]) {
                        effort[nr][nc] = next_effort;
                        pq.push({next_effort, nr, nc});
                    }
                }
            }
        }
        
        return 0; // Fallback (Constraints guarantee a path exists)
    }
};