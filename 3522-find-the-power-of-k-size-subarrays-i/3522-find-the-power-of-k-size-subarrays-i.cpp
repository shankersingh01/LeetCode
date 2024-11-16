class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;
        int windowStart = 0;
        int consecutiveCount = 1;

        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            if (windowEnd > 0 && nums[windowEnd - 1] + 1 == nums[windowEnd]) {
                consecutiveCount++;
            }

            // Ensure the window size remains equal to `k`
            if (windowEnd - windowStart + 1 > k) {
                // If the element leaving the window was part of a consecutive
                // sequence, decrement the count
                if (nums[windowStart] + 1 == nums[windowStart + 1]) {
                    consecutiveCount--;
                }
                windowStart++;
            }

            if (windowEnd - windowStart + 1 == k) {
                result.push_back(consecutiveCount == k ? nums[windowEnd] : -1);
            }
        }

        return result;
    }
};
