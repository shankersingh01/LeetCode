class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // bool limitFlag = false;
        int limit = 1;
        int k = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
                limit = 1;
            }
            else if (nums[i] == nums[i - 1] && limit < 2) {
                nums[k++] = nums[i];
                limit++;
            }
        }
        return k;
    }
};