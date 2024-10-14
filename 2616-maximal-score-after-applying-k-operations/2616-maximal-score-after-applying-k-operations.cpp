class Solution {
public:
    void ceilValue(int& maxValue) { maxValue = (maxValue + 2) / 3; }

    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        long long score = 0;
        for (int i = 1; i <= k; ++i) {
            int maxValue = maxHeap.top();
            score += maxValue;
            if (maxValue == 1) {
                score += (k - i);
                break;
            }
            ceilValue(maxValue);
            maxHeap.pop();
            maxHeap.push(maxValue);
        }
        return score;
    }
};