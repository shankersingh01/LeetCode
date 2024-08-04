class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long modulo = 1000000007;
        vector<int> prefixSum;

        for (int start = 0; start < nums.size(); ++start) {
            int prefix = 0;
            for (int end = start; end < nums.size(); ++end) {
                prefix += nums[end];
                prefixSum.push_back(prefix);
            }
        }
        sort(prefixSum.begin(), prefixSum.end());
        long long rangeSum = 0;

        for (left; left <= right; left++) {
            rangeSum = (rangeSum + prefixSum[left - 1]) % modulo;
        }

        return rangeSum;
    }
};