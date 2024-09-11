class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<30> binaryStart(start);
        bitset<30> binaryGoal(goal);
        int count = 0;
        for (int i = 0; i < 30; ++i) {
            int xorr = binaryStart[i] ^ binaryGoal[i];
            if (xorr != 0) {
                count++;
            }
        }
        return count;
    }
};