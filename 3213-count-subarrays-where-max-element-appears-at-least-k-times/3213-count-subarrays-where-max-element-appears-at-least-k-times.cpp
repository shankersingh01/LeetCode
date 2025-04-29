class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int left = 0, maxCount = 0;
        long long result = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == maxEle)
                maxCount++;
            while (maxCount >= k && left < nums.size()) {
                result += nums.size() - right;
                nums[left] == maxEle ? maxCount-- : maxCount;
                left++;
            }
        }
        return result;
    }
};