class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int start = 0, end = skill.size() - 1;

        int initSum = skill[start] + skill[end];
        long long totChemSum = 0;
        while (start < end) {
            int sum = skill[start] + skill[end];
            if (sum == initSum) {
                totChemSum += skill[start] * skill[end];
            } else {
                return -1;
            }
            start++;
            end--;
        }
        return totChemSum;
    }
};