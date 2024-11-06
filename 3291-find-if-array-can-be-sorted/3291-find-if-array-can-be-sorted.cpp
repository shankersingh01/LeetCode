class Solution {
public:
    int countBits(int num) { return bitset<32>(num).count(); }

    bool canSortArray(vector<int>& nums) {
        int prevMax = 0;
        int currMax = nums[0];
        int currMin = nums[0];
        int bitCount = countBits(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            if (bitCount == countBits(nums[i])) {
                currMax = max(currMax, nums[i]);
                currMin = min(currMin, nums[i]);
            } else {
                if (currMin < prevMax)
                    return false;
                prevMax = currMax;
                currMax = nums[i];
                currMin = nums[i];
                bitCount = countBits(nums[i]);
            }
        }
        return currMin > prevMax;
    }
};
