class Solution {
public:
    int maximumSwap(int num) {
        unordered_map<char, int> indexMapOfMaxValues;

        string strNum = to_string(num);

        vector<char> maxValueWindow(strNum.size(), 0);
        int maxValue = -1;
        int maxValueIndex = 0;
        for (int i = strNum.size() - 1; i >= 0; --i) {
            if (maxValue < strNum[i]) {
                maxValue = strNum[i];
                indexMapOfMaxValues[maxValue] = i;
            }
            maxValueWindow[i] = maxValue;
        }

        for (int i = 0; i < strNum.size(); ++i) {
            if (strNum[i] < maxValueWindow[i]) {
                int j = indexMapOfMaxValues[maxValueWindow[i]];
                swap(strNum[i], strNum[j]);
                break;
            }
        }
        return stoi(strNum);
    }
};
