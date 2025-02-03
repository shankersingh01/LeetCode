class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incCount = 1;
        int decCount = 1;
        int result = 0;

        if (nums.size() == 1)
            return 1;

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                incCount++;
                decCount = 1;
            }
            if (nums[i] > nums[i + 1]) {
                incCount = 1;
                decCount++;
            }
            if (nums[i] == nums[i + 1]) {
                incCount = 1;
                decCount = 1;
            }
            int maxCount = max(incCount, decCount);
            result = max(maxCount, result);
        }

        return result;
    }
};