class Solution {
private:
    int expressionCount(vector<int>& nums, int target, int idx, int currSum) {
        if (idx == nums.size())
            return (currSum == target) ? 1 : 0;

        int add = expressionCount(nums, target, idx + 1, currSum + nums[idx]);
        int sub = expressionCount(nums, target, idx + 1, currSum - nums[idx]);

        return add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return expressionCount(nums, target, 0, 0);
    }
};