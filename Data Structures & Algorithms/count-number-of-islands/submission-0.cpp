
   class Solution {
private:
    void bfs(int r, int c, int rows, int cols, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({r, c});
        
        // Mark as visited immediately by changing '1' to '0'
        grid[r][c] = '0'; 
        
        // Array of the 4 allowed directions: {Up, Down, Left, Right}
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            
            // Check all 4 adjacent neighbors
            for (auto dir : directions) {
                int nextRow = currRow + dir.first;
                int nextCol = currCol + dir.second;
                
                // 1. Boundary Check
                // 2. Unvisited Land Check ('1')
                if (nextRow >= 0 && nextRow < rows && 
                    nextCol >= 0 && nextCol < cols && 
                    grid[nextRow][nextCol] == '1') {
                    
                    q.push({nextRow, nextCol});
                    grid[nextRow][nextCol] = '0'; // Sink the land so we don't revisit it
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        // Base case safety check
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                
                // If we find unvisited land, we found a new island!
                if (grid[r][c] == '1') {
                    islands++;
                    bfs(r, c, rows, cols, grid);
                }
            }
        }
        
        return islands;
    }
};