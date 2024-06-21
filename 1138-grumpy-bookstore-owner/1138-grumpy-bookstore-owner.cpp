class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initialSum = 0;
        for (int i = 0; i < grumpy.size(); ++i) {
            if (grumpy[i] == 0) {
                initialSum += customers[i];
            }
        }

        int maxGrumpySum = 0;
        for(int i=0; i<=grumpy.size()-minutes; ++i){
            int j=0, k=i;
            int currGrumpySum = 0;
            while (j < minutes) {
                currGrumpySum += grumpy[k] * customers[k];
                j++;
                k++;
            }
            maxGrumpySum = max(maxGrumpySum, currGrumpySum);
            // i++;
        }
        return initialSum + maxGrumpySum;
    }
};