class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long sum = 0, minDiff = 0, maxDiff = 0;

        for (int num : differences) {
            sum += num;
            minDiff = min(minDiff, sum);
            maxDiff = max(maxDiff, sum);
        }
        return max(0L, upper - lower - maxDiff + minDiff + 1);
    }
};