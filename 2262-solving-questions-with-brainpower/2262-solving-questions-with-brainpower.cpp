class Solution {
public:
    long long dp[200001] = {{0}};

    long long getPoints(int idx, vector<vector<int>>& questions, int n) {

        if (dp[idx] != 0)
            return dp[idx];

        if (idx == n - 1)
            return questions[idx][0];
        if (idx >= n)
            return 0;

        long long select = questions[idx][0] +
                           getPoints(idx + questions[idx][1] + 1, questions, n);
        long long ignore = 0 + getPoints(idx + 1, questions, n);

        return dp[idx] = max(select, ignore);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        return getPoints(0, questions, n);
    }
};