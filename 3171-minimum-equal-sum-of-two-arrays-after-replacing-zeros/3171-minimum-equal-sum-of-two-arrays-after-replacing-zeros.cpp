class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int nums1zeroCount = 0, nums2zeroCount = 0;
        for (long long num : nums1) {
            if (num == 0) {
                nums1zeroCount++;
                sum1++;
            }
            sum1 += num;
        }
        for (long long num : nums2) {
            if (num == 0) {
                nums2zeroCount++;
                sum2++;
            }
            sum2 += num;
        }
        if (sum1 < sum2 && nums1zeroCount > 0) {
            return sum2;
        }
        if (sum1 > sum2 && nums2zeroCount > 0) {
            return sum1;
        }
        if (sum1 == sum2)
            return sum1;

        return -1;
    }
};
