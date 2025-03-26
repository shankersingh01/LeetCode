class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> grid1D;

        for (const auto& row : grid) {
            for (int num : row) {
                grid1D.emplace_back(num);
            }
        }
        
        sort(grid1D.begin(), grid1D.end());

        int median = grid1D.size() / 2;
        int operationCount = 0;
        for (int i = 0; i < grid1D.size(); ++i) {
            int absDiff = abs(grid1D[i] - grid1D[median]);
            if (absDiff % x != 0)
                return -1;
            else
                operationCount += abs(grid1D[i] - grid1D[median]) / x;
        }
        return operationCount;
    }
};