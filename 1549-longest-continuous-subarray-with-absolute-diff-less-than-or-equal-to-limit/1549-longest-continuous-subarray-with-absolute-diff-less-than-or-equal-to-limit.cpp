class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int start = 0, maxSubLen = 0;
        for (int end = 0; end < nums.size(); ++end) {
            while (!maxDeque.empty() && nums[end] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            while (!minDeque.empty() && nums[end] < minDeque.back()) {
                minDeque.pop_back();
            }
            maxDeque.push_back(nums[end]);
            minDeque.push_back(nums[end]);

            while (maxDeque.front() - minDeque.front() > limit) {
                if (nums[start] == maxDeque.front()) {
                    maxDeque.pop_front();
                }
                if (nums[start] == minDeque.front()) {
                    minDeque.pop_front();
                }
                ++start;
            }
            maxSubLen = max(maxSubLen, end - start + 1);
        }
        return maxSubLen;
    }
};