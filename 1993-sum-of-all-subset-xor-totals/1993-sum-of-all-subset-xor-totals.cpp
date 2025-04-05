class Solution {
public:
    void dfs(int index, vector<int>& nums, vector<int>& currentSubset,
             vector<vector<int>>& xorSubset) {
        // base case
        if (index == nums.size()) {
            xorSubset.push_back(currentSubset);
            return;
        }

        // include this number
        currentSubset.push_back(nums[index]);
        dfs(index + 1, nums, currentSubset, xorSubset);

        // exclude the number
        currentSubset.pop_back();
        dfs(index + 1, nums, currentSubset, xorSubset);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> xorSubset;
        vector<int> currentSubset;
        dfs(0, nums, currentSubset, xorSubset);

        int sum = 0;

        for (const auto& row : xorSubset) {
            int xorr = 0;
            for (int num : row) {
                xorr ^= num;
            }
            sum += xorr;
        }
        return sum;
    }
};