class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitCount = __builtin_popcount(num2);
        int result = 0;

        for (int i = 31; i >= 0 && setBitCount > 0; i--) {
            if (num1 & (1 << i)) {
                result |= (1 << i);
                setBitCount--;
            }
        }

        for (int i = 0; i < 32 && setBitCount > 0; ++i) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                setBitCount--;
            }
        }
        return result;
    }
};