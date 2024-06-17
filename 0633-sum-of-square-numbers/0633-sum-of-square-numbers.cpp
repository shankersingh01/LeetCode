class Solution {
public:
    bool judgeSquareSum(int c) {
        long long start = 0, end = sqrt(c);
        long long mid = start + (end - start) / 2;
        while (start <= end) {
            long long a = start * start;
            long long b = end * end;
            if (a > c) {
                return false;
            } else if (a + b == c) {
                return true;
            } else if (a + b > c) {
                end--;
            } else {
                start++;
            }
        }
        return false;
    }
};