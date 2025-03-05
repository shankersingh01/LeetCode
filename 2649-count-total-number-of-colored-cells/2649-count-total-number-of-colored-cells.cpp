class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1)
            return 1;
        int i = 1;
        long long sum = 1;
        while (n-- > 1) {
            sum += (4 * i++);
        }
        return sum;
    }
};