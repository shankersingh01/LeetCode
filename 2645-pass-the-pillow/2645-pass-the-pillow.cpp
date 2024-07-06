class Solution {
public:
    int passThePillow(int n, int time) {
        int direction = 1;
        int index = 1;
        for (int i = 1; i <= time; ++i) {
            index += direction;
            if (index == 1 || index == n) {
                direction *= -1;
            }
        }
        return index;
    }
};