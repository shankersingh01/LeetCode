class Solution {
public:
    int maximumSwap(int num) {

        string strNum = to_string(num);

        vector<int> rightMaxIndex(strNum.size());
        int maxValueIndex = strNum.size() - 1;

        for (int i = strNum.size() - 1; i >= 0; --i) {
            if (strNum[maxValueIndex] < strNum[i]) {
                maxValueIndex = i;
            }
            rightMaxIndex[i] = maxValueIndex;
        }

        for (int i = 0; i < strNum.size(); ++i) {
            int j = rightMaxIndex[i];
            if (strNum[i] < strNum[j]) {
                swap(strNum[i], strNum[j]);
                return stoi(strNum);
            }
        }
        return num;
    }
};
