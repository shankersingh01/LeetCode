class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int sumDigit = 0;
            int num = nums[i];
            while (num > 0) {
                sumDigit += num % 10;
                num /= 10;
            }
            if (mp.find(sumDigit) != mp.end()) {
                int pairSum = mp[sumDigit] + nums[i];
                ans.push_back(pairSum);
                mp.erase(sumDigit);
            } else
                mp[sumDigit] = nums[i];
        }

        int maxPairSum =
            !ans.empty() ? *max_element(ans.begin(), ans.end()) : -1;
        return maxPairSum;
    }
};