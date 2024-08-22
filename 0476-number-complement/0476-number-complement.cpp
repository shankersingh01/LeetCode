class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
            return 1;

        int bitLength = 0;
        int n = num;
        while (n > 0) {
            n >>= 1;
            bitLength++;
        }

        unsigned int mask = (1U << bitLength) - 1;

        return num ^ mask;
    }
};
