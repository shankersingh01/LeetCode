class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> pairFreq;
        int totalDominoPairs = 0;
        for (const auto& pair : dominoes) {
            int firstNum = pair[0];
            int secondNum = pair[1];
            int key = firstNum < secondNum ? firstNum * 10 + secondNum
                                           : secondNum * 10 + firstNum;
            totalDominoPairs += pairFreq[key];
            pairFreq[key]++;
        }
        return totalDominoPairs;
    }
};