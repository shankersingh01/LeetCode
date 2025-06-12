class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i != nums.size() - 1) {
                maxDiff = max(abs(nums[i] - nums[i + 1]), maxDiff);
            } else {
                maxDiff = max(abs(nums[i] - nums[0]), maxDiff);
            }
        }
        return maxDiff;
    }
};