class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1)
            return '0';

        int strLength = (1 << n) - 1;

        int mid = (strLength / 2) + 1;

        if (mid == k)
            return '1';

        if (k < mid)
            return findKthBit(n - 1, k);

        return findKthBit(n - 1, strLength - k + 1) == '0' ? '1' : '0';
    }
};