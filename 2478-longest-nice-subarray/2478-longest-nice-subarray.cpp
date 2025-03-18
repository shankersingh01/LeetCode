class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLen = 1;
        int left = 0;
        int usedBits = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while ((usedBits & nums[i]) != 0) {
                usedBits ^= nums[left];
                left++;
            }
            usedBits |= nums[i];
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};