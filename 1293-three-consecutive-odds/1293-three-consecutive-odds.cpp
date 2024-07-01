class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCount = 0;
        for (int num : arr) {
            if (num & 1) {
                oddCount++;
                if (oddCount >= 3) {
                    return true;
                }
            } else
                oddCount = 0;
        }
        return false;
    }
};