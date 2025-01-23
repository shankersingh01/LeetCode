class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rowServerCount;
        for (auto row : grid) {
            int serverCount = 0;
            for (auto col : row) {
                if (col == 1) {
                    serverCount++;
                }
            }
            rowServerCount.push_back(serverCount);
        }
        vector<int> colServerCount;
        for (int i = 0; i < grid[0].size(); ++i) {
            int serverCount = 0;
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[j][i] == 1) {
                    serverCount++;
                }
            }
            colServerCount.push_back(serverCount);
        }

        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 &&
                    (rowServerCount[i] > 1 || colServerCount[j] > 1)) {

                    result++;
                }
            }
        }
        return result;
    }
};