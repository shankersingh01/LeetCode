class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> balls, colors;
        vector<int> result;

        for (auto query : queries) {
            int ball = query[0];
            int color = query[1];

            if (balls.find(ball) != balls.end()) {
                colors[balls[ball]]--;
                if (colors[balls[ball]] == 0) {
                    colors.erase(balls[ball]);
                }
            }
            balls[ball] = color;
            colors[color]++;
            result.push_back(colors.size());
        }
        return result;
    }
};