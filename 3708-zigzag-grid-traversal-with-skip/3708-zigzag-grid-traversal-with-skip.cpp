class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;
        int count = 0;
        int row = 0, col = 0;
        while (row < grid.size()) {

            if (row % 2 == 0) {
                col = 0;
                while (col < grid[0].size()) {
                    if (count % 2 == 0)
                        result.push_back(grid[row][col]);
                    count++;
                    col++;
                }
            } else {
                col = grid[0].size()-1;
                while (col >= 0) {
                    if (count % 2 == 0)
                        result.push_back(grid[row][col]);
                    count++;
                    col--;
                }
            }
            row++;
        }
        return result;
    }
};