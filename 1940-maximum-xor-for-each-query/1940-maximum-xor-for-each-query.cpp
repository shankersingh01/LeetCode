class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mask = (1LL << maximumBit) - 1;
        int xorr = 0;
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            xorr ^= nums[i];
            result[nums.size() - 1 - i] = ~xorr & mask;
        }
        return result;
    }
};
