class Solution {
public:
    int dfs(vector<vector<int>>& island, int& count, int i, int j) {
        int row = island.size();
        int col = island[0].size();

        if (i < 0 || j < 0 || i >= row || j >= col || island[i][j] == 0) {
            return count;
        }

        count++;
        island[i][j] = 0;
        dfs(island, count, i, j + 1); // right
        dfs(island, count, i - 1, j); // up
        dfs(island, count, i, j - 1); // left
        dfs(island, count, i + 1, j); // down

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> island(grid.begin(), grid.end());
        int maxIsland = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (island[i][j] == 1) {
                    int count = 0;
                    dfs(island, count, i, j);
                    maxIsland = max(maxIsland, count);
                }
            }
        }
        return maxIsland;
    }
};
