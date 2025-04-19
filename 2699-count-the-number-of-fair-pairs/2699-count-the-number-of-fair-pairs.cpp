class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long result = 0;

        for (int i = 0, j = nums.size() - 1; i < j; ++i) {
            while (i < j && nums[i] + nums[j] > k) {
                j--;
            }
            result += j - i;
        }
        return result;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countPairs(nums, upper) - countPairs(nums, lower - 1);
    }
};