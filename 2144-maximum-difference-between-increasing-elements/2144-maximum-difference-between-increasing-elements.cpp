class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[i] && maxDiff < nums[j] - nums[i]) {
                    maxDiff = nums[j] - nums[i];
                }
            }
        }
        return maxDiff;
    }
};