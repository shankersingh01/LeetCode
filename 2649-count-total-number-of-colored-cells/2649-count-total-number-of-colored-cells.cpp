class Solution {
public:
    long long coloredCells(int n) {
        if (n == 1)
            return 1;
        int i = 1;
        long long sum = 0;
        while (n-- > 1) {
            sum += (4 * i);
            i++;
        }
        return sum + 1;
    }
};