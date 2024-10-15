class Solution {
public:
    long long minimumSteps(string s) {
        int zeroCount = 0;
        long long minSwap = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                zeroCount++;
            } else {
                minSwap += zeroCount;
            }
        }
        return minSwap;
    }
};
