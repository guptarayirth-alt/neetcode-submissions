class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int ROWS = grid.size();
        int COLS = grid[0].size();
        
        // Lambda to convert a 2D coordinate into a unique 1D ID
        auto getId = [&](int r, int c) {
            return r * COLS + c;
        };
        
        // Neighbor map: Maps a cell's ID to a list of its valid adjacent fruit IDs
        unordered_map<int, vector<int>> adj;
        queue<int> q;
        int freshCount = 0;
        
        // 1. Build the neighbor map and prime the BFS queue
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                // We don't care about mapping empty cells
                if (grid[r][c] == 0) continue; 
                
                int u = getId(r, c);
                
                // Track fresh fruits and prime the queue with rotten ones
                if (grid[r][c] == 1) {
                    freshCount++;
                } else if (grid[r][c] == 2) {
                    q.push(u);
                }
                
                // Look in all 4 directions to build edges for our graph
                int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (int d = 0; d < 4; d++) {
                    int nr = r + directions[d][0];
                    int nc = c + directions[d][1];
                    
                    // If the neighbor is within bounds AND has a fruit (1 or 2)
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] != 0) {
                        int v = getId(nr, nc);
                        adj[u].push_back(v);
                    }
                }
            }
        }
        
        // If there are zero fresh fruits to start, it takes 0 minutes
        if (freshCount == 0) return 0;
        
        // 2. Execute Multi-Source BFS using the neighbor map
        int minutes = 0;
        
        while (!q.empty()) {
            int qLen = q.size();
            bool rottedAny = false; // Flag to track if we rotted fruit in this layer
            
            for (int i = 0; i < qLen; i++) {
                int curr = q.front();
                q.pop();
                
                // Iterate through the pre-mapped neighbors
                for (int neighbor : adj[curr]) {
                    // Convert the 1D ID back to 2D coordinates to check grid state
                    int r = neighbor / COLS;
                    int c = neighbor % COLS;
                    
                    // If the neighbor is fresh, rot it
                    if (grid[r][c] == 1) {
                        grid[r][c] = 2;       // Mark as rotten (visited)
                        freshCount--;         // Decrement our target count
                        q.push(neighbor);     // Add to next layer
                        rottedAny = true;
                    }
                }
            }
            
            // Only increment time if we successfully rotted fruits during this minute
            if (rottedAny) {
                minutes++;
            }
        }
        
        // 3. Check the final result
        // If we still have fresh fruits left, they were unreachable
        return freshCount == 0 ? minutes : -1;
    }
};