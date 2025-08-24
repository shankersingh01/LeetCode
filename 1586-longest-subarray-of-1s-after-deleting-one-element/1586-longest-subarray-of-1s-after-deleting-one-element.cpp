class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // we will count only 1
        // if all 1s then check if 1 count is equal to arr size if yes then
        // reduce count by 1
        int oneCount = 0, result = 0;
        int zeroCount = 0;
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right] == 0)
                zeroCount++;
            else
                oneCount++;
            while (zeroCount > 1) {
                if (nums[left] == 1)
                    oneCount--;
                else
                    zeroCount--;
                left++;
            }
            result = max(result, oneCount);
            right++;
        }
        return (result == nums.size()) ? result - 1 : result;
    }
};