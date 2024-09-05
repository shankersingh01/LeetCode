class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int rollsSum = 0;
        for (int i = 0; i < rolls.size(); ++i) {
            rollsSum += rolls[i];
        }

        int totalSum = (n + rolls.size()) * mean;
        int reqSum = totalSum - rollsSum;

        if (reqSum > 6 * n || reqSum < n) {
            return {};
        }

        int rem =
            reqSum % n; // to add the rem to one or more elements of the array
        int potentialNum =
            reqSum / n; // this could be the only number filling the array

        vector<int> missingArr(n, potentialNum);
        for (int i = 1; i <= rem; ++i) {
            missingArr[i]++;
        }
        return missingArr;
    }
};
