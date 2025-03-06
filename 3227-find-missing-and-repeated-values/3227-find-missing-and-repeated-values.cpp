class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int gridSize = grid.size();
        vector<int> freq(gridSize * gridSize + 1);

        for (auto row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }
        int repeatedNum = 0, missingNum = 0;
        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i] > 1)
                repeatedNum = i;
            if (freq[i] < 1)
                missingNum = i;
        }
        vector<int> ans(2, 0);
        ans[0] = repeatedNum;
        ans[1] = missingNum;
        return ans;
    }
};