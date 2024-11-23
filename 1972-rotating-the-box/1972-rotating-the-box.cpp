class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int rows = box.size();
        int columns = box[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = columns - 1; j >= 1; j--) {
                while (j < columns && box[i][j] == '.' &&
                       box[i][j - 1] == '#') {
                    swap(box[i][j], box[i][j - 1]);
                    j++;
                }
            }
        }

        vector<vector<char>> result;
        for (int i = 0; i < columns; i++) {
            vector<char> newRow;
            for (int j = rows - 1; j >= 0; j--) {
                newRow.push_back(box[j][i]);
            }
            result.push_back(newRow);
        }

        return result;
    }
};
