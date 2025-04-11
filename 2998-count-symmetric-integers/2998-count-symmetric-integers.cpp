class Solution {
public:
    bool checkSymmetricSum(int num) {
        string val = to_string(num);

        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < val.size(); ++i) {
            if (i < val.size() / 2) {
                leftSum += val[i] - '0';
            } else
                rightSum += val[i] - '0';
        }
        return leftSum == rightSum;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int i = low; i <= high; ++i) {
            string val = to_string(i);
            if (val.size() % 2 == 0 && checkSymmetricSum(i)) {
                count++;
            }
        }
        return count;
    }
};