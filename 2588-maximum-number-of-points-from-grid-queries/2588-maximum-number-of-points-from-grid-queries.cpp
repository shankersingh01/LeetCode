class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int, int>> queriesCopy(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            queriesCopy.emplace_back(queries[i], i);
        }
        sort(queriesCopy.begin(), queriesCopy.end());

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            minHeap;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        minHeap.emplace(grid[0][0], make_pair(0, 0));
        int points = 0;
        visited[0][0] = true;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> result(queries.size(), 0);

        for (auto& [queryVal, queryIndex] : queriesCopy) {
            while (!minHeap.empty() && minHeap.top().first < queryVal) {
                auto [val, pos] = minHeap.top();
                minHeap.pop();
                int row = pos.first, col = pos.second;
                points++;

                for (const auto& [r, c] : directions) {
                    int newRow = row + r, newCol = col + c;
                    if (newRow >= 0 && newRow < grid.size() && newCol >= 0 &&
                        newCol < grid[0].size() && !visited[newRow][newCol]) {
                        minHeap.emplace(grid[newRow][newCol],
                                        make_pair(newRow, newCol));
                        visited[newRow][newCol] = true;
                    }
                }
            }
            result[queryIndex] = points;
        }
        return result;
    }
};