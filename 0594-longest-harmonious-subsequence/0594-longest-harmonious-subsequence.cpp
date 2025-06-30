class Solution {
public:
    int findLHS(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());

        int left = 0, right = 0;
        int maxLen = 0;

        while (right < temp.size()) {
            if (temp[right] - temp[left] == 1) {
                maxLen = max(right - left + 1, maxLen);
            } else {
                while (temp[right] - temp[left] > 1) {
                    left++;
                }   
            }
            right++;
        }
        return maxLen;
    }
};
// 1,2,2,2,3,3,5,7