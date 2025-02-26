class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int posSum = 0, negSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            posSum += nums[i];
            maxSum = max(maxSum, posSum);
            if (posSum < 0)
                posSum = 0;

            negSum += nums[i];
            minSum = min(minSum, negSum);
            if (negSum > 0)
                negSum = 0;
        }

        return abs(maxSum) >= abs(minSum) ? abs(maxSum) : abs(minSum);
    }
};
