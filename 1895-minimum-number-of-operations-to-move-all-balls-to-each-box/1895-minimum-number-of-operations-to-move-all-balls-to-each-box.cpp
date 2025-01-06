class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> index;

        for (int i = 0; i < boxes.size(); ++i) {
            if (boxes[i] == '1') {
                index.push_back(i);
            }
        }
        vector<int> result;

        for (int i = 0; i < boxes.size(); ++i) {
            int minOperation = 0;
            for (int j = 0; j < index.size(); ++j) {
                minOperation += abs(i - index[j]);
            }
            result.push_back(minOperation);
        }
        return result;
    }
};