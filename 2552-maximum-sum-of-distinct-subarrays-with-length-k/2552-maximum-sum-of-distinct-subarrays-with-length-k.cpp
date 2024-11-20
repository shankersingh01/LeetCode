class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_set<int> uniqueElements;
        int left = 0, right = 0, end = nums.size() - 1;
        long long sum = 0, maxSum = 0;

        if (k > nums.size()) {
            return 0;
        }

        while (right <= end) {

            while (uniqueElements.find(nums[right]) != uniqueElements.end() ||
                   right - left + 1 > k) {
                sum -= nums[left];
                uniqueElements.erase(nums[left]);
                left++;
            }

            sum += nums[right];
            uniqueElements.insert(nums[right]);

            if (right - left + 1 == k) {
                maxSum = max(maxSum, sum);
            }
            right++;
        }

        return maxSum;
    }
};