class Solution {
public:
    bool findNext(vector<int>& hand, int groupSize, int i) {
        int next = hand[i] + 1;
        hand[i] = -1;
        int count = 1;
        for (i = i + 1; i < hand.size() && count < groupSize; i++) {
            if (hand[i] == next) {
                next++;
                hand[i] = -1;
                count++;
            }
        }
        return count == groupSize;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        for (int i = 0; i < hand.size(); ++i) {
            if (hand[i] >= 0) {
                if (!findNext(hand, groupSize, i))
                    return false;
            }
        }
        return true;
    }
};