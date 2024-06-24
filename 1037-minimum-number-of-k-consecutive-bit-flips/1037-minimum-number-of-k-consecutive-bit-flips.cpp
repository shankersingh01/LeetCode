class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flipped = 0;
        int flipCount = 0;

        vector<int> FlippedArr(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                flipped ^= FlippedArr[i - k];
            }
            if (flipped == nums[i]) {
                if (i + k > nums.size()) {
                    return -1;
                }
                FlippedArr[i] = 1;
                flipped ^= 1;
                flipCount++;
            }
        }
        return flipCount;
    }
};