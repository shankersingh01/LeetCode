class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        for (int i = 1; i <= numBottles; ++i) {
            if (i % numExchange == 0) {
                numBottles++;
            }
        }
        return numBottles;
    }
};