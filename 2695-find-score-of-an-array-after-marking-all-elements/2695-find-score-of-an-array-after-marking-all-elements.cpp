class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }

        vector<int> marked(nums.size(), 0);
        long long score = 0;

        while (!pq.empty()) {
            int index = pq.top().second;
            if (marked[index] == 0) {
                score += pq.top().first;
                if (index > 0) {
                    marked[index - 1] = 1;
                }
                if (index < nums.size() - 1) {
                    marked[index + 1] = 1;
                }
                marked[index] = 1;
            }
            pq.pop();
        }
        return score;
    }
};
