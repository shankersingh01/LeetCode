class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1)
            return nums;

        vector<int> results;

        for (int i = 0; i <= nums.size() - k; ++i) {
            bool flag = false;
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1] || nums[j+1] != nums[j]+1) {
                    results.push_back(-1);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                results.push_back(nums[i + k - 1]);
            }
        }
        return results;
    }
};