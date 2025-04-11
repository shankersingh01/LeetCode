class Solution {
public:
    bool checkSymmetricSum(int num) {
        string val = to_string(num);
    
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < val.size(); ++i) {
            if (i < val.size() / 2) {
                sum1 += val[i] - '0';
            } else
                sum2 += val[i] - '0';
        }
        return sum1 == sum2;
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