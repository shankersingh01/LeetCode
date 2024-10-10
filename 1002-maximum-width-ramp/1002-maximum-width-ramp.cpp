class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> stk;

        for (int i = 0; i < nums.size(); ++i) {
            if (stk.empty() || nums[i] < nums[stk.top()]) {
                stk.push(i);
            }
        }
        int maxRampDist = 0;
        for (int j = nums.size() - 1; j >= 0; --j) {
            while (!stk.empty() && nums[j] >= nums[stk.top()]) {
                maxRampDist = max(maxRampDist, j - stk.top());
                stk.pop();
            }
        }
        return maxRampDist;
    }
};

// once you find a ramp then searching for another ramp should always be bigger
// right
