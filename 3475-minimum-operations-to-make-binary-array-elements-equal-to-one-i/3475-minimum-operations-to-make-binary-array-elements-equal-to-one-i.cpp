class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> numsCopy(nums.begin(), nums.end());
        int operationCount = 0;

        for (int i = 0; i < numsCopy.size(); ++i) {
            if (numsCopy[i] == 0) {
                if (i <= numsCopy.size() - 3) {
                    operationCount++;
                    numsCopy[i] = !numsCopy[i];
                    numsCopy[i + 1] = !numsCopy[i + 1];
                    numsCopy[i + 2] = !numsCopy[i + 2];
                } else
                    return -1;
            }
        }
        return operationCount;
    }
};