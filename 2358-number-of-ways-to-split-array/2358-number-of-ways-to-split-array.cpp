class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }

        long long currSum = 0;
        int validSplitCount = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            currSum += nums[i];
            sum -= nums[i];
            if (currSum >= sum) {
                validSplitCount++;
            }
        }
        return validSplitCount;
    }
};