class Solution {
public:
    void dfs(vector<vector<char>>& visited, int i, int j) {
        if (i < 0 || j < 0 || i >= visited.size() || j >= visited[0].size() ||
            visited[i][j] == '0')
            return;

        visited[i][j] = '0';
        dfs(visited, i + 1, j); // down
        dfs(visited, i - 1, j); // up
        dfs(visited, i, j + 1); // right
        dfs(visited, i, j - 1); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> visitedGrid(grid.begin(), grid.end());
        int islandCount = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (visitedGrid[i][j] == '1') {
                    islandCount++;
                    dfs(visitedGrid, i, j);
                }
            }
        }
        return islandCount;
    }
};