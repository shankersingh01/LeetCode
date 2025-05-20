class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size() + 1, 0);
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            diff[left] += 1;
            diff[right + 1] -= 1;
        }
        if (nums[0] - diff[0] > 0)
            return false;
        for (int i = 1; i < nums.size(); ++i) {
            diff[i] = diff[i] + diff[i - 1];
            if (nums[i] - diff[i] > 0) {
                return false;
            }
        }
        return true;
    }
};
