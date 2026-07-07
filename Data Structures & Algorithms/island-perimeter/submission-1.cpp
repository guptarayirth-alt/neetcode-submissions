class Solution {
public:
    
        int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int perimeter = 0;
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 1) {
                perimeter += 4; // Add 4 for the land cell
                
                // Check if there is a land neighbor to the RIGHT
                if (c + 1 < cols && grid[r][c + 1] == 1) {
                    perimeter -= 2;
                }
                // Check if there is a land neighbor DOWN
                if (r + 1 < rows && grid[r + 1][c] == 1) {
                    perimeter -= 2;
                }
            }
        }
    }
    return perimeter;
}
        
    
};