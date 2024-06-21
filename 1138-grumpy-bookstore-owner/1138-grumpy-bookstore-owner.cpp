class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initialSum = 0;
        for (int i = 0; i < grumpy.size(); ++i) {
            if (grumpy[i] == 0) {
                initialSum += customers[i];
            }
        }

        int currGrumpySum = 0;
        for (int i = 0; i < minutes; ++i) {
            currGrumpySum += customers[i] * grumpy[i];
        }
        int maxGrumpySum = currGrumpySum;

        for (int i = minutes; i < grumpy.size(); ++i) {
            currGrumpySum += customers[i] * grumpy[i];
            currGrumpySum -= customers[i - minutes] * grumpy[i - minutes];
            maxGrumpySum = max(maxGrumpySum, currGrumpySum);
        }

        return initialSum + maxGrumpySum;
    }
};