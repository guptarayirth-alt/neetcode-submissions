#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Helper function that acts as your "explorer"
    int exploreIsland(vector<vector<int>>& grid, int r, int c, int rows, int cols) {
        // 1. Base Case: If we go out of bounds, or hit water (0), stop and return an area of 0.
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 0;
        }
        
        // 2. Mark as visited: Change the 1 to a 0 so we don't get stuck in an infinite loop.
        grid[r][c] = 0; 
        
        // 3. Count this cell (1) + explore all 4 directions to find connected land
        int area = 1;
        area += exploreIsland(grid, r + 1, c, rows, cols); // Down
        area += exploreIsland(grid, r - 1, c, rows, cols); // Up
        area += exploreIsland(grid, r, c + 1, rows, cols); // Right
        area += exploreIsland(grid, r, c - 1, rows, cols); // Left
        
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Your two outer loops i and j!
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                
                // When you detect an unvisited 1, pause and explore the whole island
                if (grid[i][j] == 1) {
                    int current_island_area = exploreIsland(grid, i, j, rows, cols);
                    
                    // Keep track of the largest island found so far
                    max_area = max(max_area, current_island_area);
                }
            }
        }
        
        return max_area;
    }
};