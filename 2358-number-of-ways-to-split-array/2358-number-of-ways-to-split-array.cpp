class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Calculate the sum of array then keep processing elements from 0 to
        // n-2
        //  for each i add to curr sum and subtract it from the sum and if
        //  condition to check if it satisfies the problem condition and
        //  increment the valid splits count if it does
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