class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int posSum = 0, negSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            posSum += nums[i];
            if (posSum < 0)
                posSum = 0;
            maxSum = max(maxSum, posSum);

            negSum += nums[i];
            if (negSum > 0)
                negSum = 0;
            minSum = min(minSum, negSum);
        }

        return abs(maxSum) >= abs(minSum) ? abs(maxSum) : abs(minSum);
    }
};
