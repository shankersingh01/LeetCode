class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long left = 0, right = 0;
        long maxFreqLen = 0, sum = 0;

        while (right < nums.size()) {
            sum += nums[right];
            long windowLen = right - left + 1;
            while (nums[right] * windowLen > sum + k) {
                sum -= nums[left];
                left++;
                windowLen--;
            }
            maxFreqLen = max(maxFreqLen, windowLen);
            right++;
        }
        return static_cast<int>(maxFreqLen);
    }
};