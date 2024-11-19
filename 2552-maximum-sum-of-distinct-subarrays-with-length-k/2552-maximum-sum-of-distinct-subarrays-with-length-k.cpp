class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // traverse till n-1
        // maintain hashmap for unique elements in the present window
        // condition to calculate max sum is if window size == k
        // condition to skip a window that does not meet the unique element
        // condition
        // if element exists in the hashmap then skip the window to the curr
        // element else add to hashmap
        unordered_set<int> uniqueElements;
        int left = 0, right = 0, end = nums.size() - 1;
        long long sum = 0, maxSum = 0;

        if (k > nums.size()) {
            return 0;
        }

        while (right <= end) {

            while (uniqueElements.find(nums[right]) != uniqueElements.end()) {
                sum -= nums[left];
                uniqueElements.erase(nums[left]);
                left++;
            }

            while (right - left + 1 > k) {
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