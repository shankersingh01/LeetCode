class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = 0;
        int prev_val = values[0];

        for (int i = 1; i < values.size(); ++i) {
            result = max(result, prev_val + values[i] - i);
            prev_val = max(prev_val, values[i] + i);
        }
        return result;
    }
};