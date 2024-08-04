class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long modulo = 1000000007;
        vector<long long> prefixSum(n + 1, 0);
        vector<long long> subarraySum;

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        for (int start = 0; start < nums.size(); ++start) {
            for (int end = start; end < nums.size(); ++end) {
                long long sum = prefixSum[end + 1] - prefixSum[start];
                subarraySum.push_back(sum);
            }
        }
        sort(subarraySum.begin(), subarraySum.end());
        long long rangeSum=0;

        for(left; left<=right; left++){
            rangeSum+=subarraySum[left-1];
        }
        rangeSum%=modulo;
        return rangeSum;
    }
};