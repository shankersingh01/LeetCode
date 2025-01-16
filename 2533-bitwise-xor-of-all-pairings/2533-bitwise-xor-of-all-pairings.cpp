class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int num1Size = nums1.size();
        int num2Size = nums2.size();

        int result = 0;

        if (num1Size % 2 == 1) {
            for (int i = 0; i < num2Size; ++i) {
                result ^= nums2[i];
            }
        }
        if (num2Size % 2 == 1) {
            for (int i = 0; i < num1Size; ++i) {
                result ^= nums1[i];
            }
        }
        return result;
    }
};
