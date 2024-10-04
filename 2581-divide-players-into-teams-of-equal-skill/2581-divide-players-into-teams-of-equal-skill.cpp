class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int start = 0, end = skill.size() - 1;

        int initSum = skill[start] + skill[end];
        long long totChemSum = 0;
        while (start < end) {
            int sum = skill[start] + skill[end];
            if (sum != initSum) {
                return -1;
            }
            totChemSum += skill[start] * skill[end];
            start++;
            end--;
        }
        return totChemSum;
    }
};