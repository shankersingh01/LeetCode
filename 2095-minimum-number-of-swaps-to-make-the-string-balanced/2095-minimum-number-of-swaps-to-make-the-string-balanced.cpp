class Solution {
public:
    int minSwaps(string s) {
        int start = 0;
        int end = s.size() - 1;
        int closeCount = 0;
        int swapCount = 0;

        while (start < end) {
            if (s[start] == '[')
                closeCount--;
            if (s[start] == ']') {
                closeCount++;
                if (closeCount > 0) {
                    while (end > start && s[end] != '[') {
                        end--;
                    }
                    swap(s[start], s[end]);
                    swapCount++;
                    closeCount -= 2;
                    end--;
                }
            }
            start++;
        }
        return swapCount;
    }
};
