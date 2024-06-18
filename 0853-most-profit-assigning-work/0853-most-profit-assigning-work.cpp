class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> jobs;

        for (int i = 0; i < profit.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int j = 0;
        int resProfit = 0;

        for (int i = 0; i < worker.size(); ++i) {
            while (worker[i] >= jobs[j].first && j < jobs.size()) {
                resProfit = max(resProfit, jobs[j].second);
                j++;
            }
            maxProfit += resProfit;
        }
        return maxProfit;
    }
};