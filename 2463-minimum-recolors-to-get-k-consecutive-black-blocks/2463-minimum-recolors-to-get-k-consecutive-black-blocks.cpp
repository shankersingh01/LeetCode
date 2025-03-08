class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // Sliding Window

        if (k > blocks.size())
            return 0;
        int blackCount = 0;
        int maxBlackCount = 0;
        for (int i = 0, j = 0; i < blocks.size() && j<blocks.size(); ++i) {
            if (blocks[i] == 'B')
                blackCount++;
            if (i > k - 1) {
                if (blocks[j] == 'B')
                    blackCount--;
                    j++;
            }
            maxBlackCount = max(blackCount, maxBlackCount);
        }
        return maxBlackCount >= k ? 0 : k - maxBlackCount;
    }
};