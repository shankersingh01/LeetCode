class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {

        unordered_map<int, int> mp;
        for (auto num : nums1) {
            mp[num[0]] += num[1];
        }

        for (auto num : nums2) {
            mp[num[0]] += num[1];
        }

        vector<vector<int>> mergedArray;
        vector<int> ans(2, 0);

        for (auto pair : mp) {
            ans[0] = pair.first;
            ans[1] = pair.second;
            mergedArray.push_back(ans);
        }
        sort(mergedArray.begin(), mergedArray.end());
        return mergedArray;
    }
};