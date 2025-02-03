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
            } else if (nums[i] > nums[i + 1]) {
                incCount = 1;
                decCount++;
            } else {
                incCount = 1;
                decCount = 1;
            }
            result = max({incCount, decCount, result});
        }
        return result;
    }
};