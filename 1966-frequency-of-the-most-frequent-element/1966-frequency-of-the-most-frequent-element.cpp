class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long left = 0, right = 0;
        long maxFreqLen = 0, sum = 0;

        while (right < nums.size()) {
            sum += nums[right];

            while (nums[right] * (right - left + 1) > sum + k) {
                sum -= nums[left];
                left++;
            }
            maxFreqLen = max(maxFreqLen, right - left + 1);
            right++;
        }
        return maxFreqLen;
    }
};