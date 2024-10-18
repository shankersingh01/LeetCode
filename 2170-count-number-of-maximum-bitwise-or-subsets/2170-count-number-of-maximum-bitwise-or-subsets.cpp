class Solution {
public:
    void backtracking(int index, int currentOR, int maxOR, int &count,
                      vector<int>& nums) {
        if (currentOR == maxOR) {
            count++;
        }

        for (int i = index; i < nums.size(); ++i) {
            backtracking(i + 1, currentOR | nums[i], maxOR, count, nums);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxBitOR = 0;
        int numSize = nums.size();
        for (int num : nums) {
            maxBitOR |= num;
        }
        vector<vector<int>> result;
        vector<int> currentSubset;
        int count = 0;
        backtracking(0, 0, maxBitOR, count, nums);

        return count;
    }
};