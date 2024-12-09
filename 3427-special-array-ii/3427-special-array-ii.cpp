class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<pair<int, int>> prefixParity(nums.size());

        int index = 0;
        prefixParity[0] = make_pair(index, 1);
        for (int i = 1; i < nums.size(); ++i) {

            if ((nums[i] % 2 == 1 && nums[i - 1] % 2 == 0) ||
                (nums[i] % 2 == 0 && nums[i - 1] % 2 == 1)) {
                prefixParity[i] = make_pair(index, 1);
            } else {
                index = i;
                prefixParity[i] = make_pair(index, 0);
            }
        }
        vector<bool> result;
        for (auto& query : queries) {
            if (prefixParity[query[1]].first <= query[0]) {
                result.push_back(true);
            } else
                result.push_back(false);
        }
        return result;
    }
};