#include <vector>

using namespace std;

class Solution {
    // DFS Helper Function
    void dfs(vector<vector<int>>& grid, int r, int c, int current_distance) {
        // 1. Base Case: Out of bounds
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return;
        }
        
        // 2. Base Case: Hit a wall (-1)
        if (grid[r][c] == -1) {
            return;
        }
        
        // 3. Optimization / Stop Condition: 
        // If the cell already has a shorter or equal distance from another treasure, stop!
        // This prevents infinite loops and massive redundant calculations.
        if (current_distance >= grid[r][c]) {
            return;
        }
        
        // 4. Update the cell with the new, shorter distance
        grid[r][c] = current_distance;
        
        // 5. Explore all 4 directions, adding 1 to the distance
        dfs(grid, r + 1, c, current_distance + 1); // Down
        dfs(grid, r - 1, c, current_distance + 1); // Up
        dfs(grid, r, c + 1, current_distance + 1); // Right
        dfs(grid, r, c - 1, current_distance + 1); // Left
    }

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // The two loops you suggested
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                
                // When we find a treasure (0), start updating the grid around it
                if (grid[i][j] == 0) {
                    
                    // We trigger the DFS on the 4 neighboring cells with a starting distance of 1.
                    // We don't trigger it directly on (i, j) because its distance is already 0.
                    dfs(grid, i + 1, j, 1);
                    dfs(grid, i - 1, j, 1);
                    dfs(grid, i, j + 1, 1);
                    dfs(grid, i, j - 1, 1);
                }
            }
        }
    }
};