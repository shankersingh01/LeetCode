class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        int res = -1;
        for (int num : nums) {
            int is_sqrt = sqrt(num);
            if (is_sqrt * is_sqrt == num && mp.find(is_sqrt) != mp.end()) {
                mp[num] = mp[is_sqrt] + 1;
                res = max(res, mp[num]);
            } else
                mp[num] = 1;
        }
        return res;
    }
};