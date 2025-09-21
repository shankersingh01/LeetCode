class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k % nums.size() == 0)
            return;
        k = k % nums.size();
        int rotateStartIdx = 0;
        if( k < nums.size()){
            rotateStartIdx = nums.size() - k;
        }
        vector<int> ans(nums.size());
        int j = 0;
        for (int i = rotateStartIdx; i < nums.size(); ++i) {
            ans[j++] = nums[rotateStartIdx++];
        }

        int i = 0;
        for (; j < nums.size(); ++j) {
            ans[j] = nums[i++];
        }
        nums = ans;
    }
};