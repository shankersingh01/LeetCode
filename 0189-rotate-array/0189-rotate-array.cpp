class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k % nums.size() == 0)
            return;
        k = k % nums.size();
        int rotateStartIdx = 0;
        if (k < nums.size()) {
            rotateStartIdx = nums.size() - k;
        }

        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = nums[(rotateStartIdx + i) % nums.size()];
        }
        nums = ans;
    }
};