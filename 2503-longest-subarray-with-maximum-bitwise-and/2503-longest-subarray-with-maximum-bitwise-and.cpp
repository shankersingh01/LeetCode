class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // finding the max value in the array
        int maxValue = *max_element(nums.begin(), nums.end());
        int count = 0;
        int maxCount = 0;
        for (int num : nums) {
            if (num == maxValue) {
                count++;
            } else {
                count = 0;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};