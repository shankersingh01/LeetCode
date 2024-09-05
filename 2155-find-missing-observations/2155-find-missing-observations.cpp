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

        vector<int> missingArr;
        while (reqSum > 0) {
            int missingNum = reqSum / n;

            missingArr.push_back(missingNum);
            reqSum -= missingNum;
            n--;
            if (n == 0)
                break;
        }
        if(n>0){
            return {};
        }
        return missingArr;
    }
};
