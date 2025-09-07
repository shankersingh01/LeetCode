class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, majEle = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                majEle = nums[i];
            }
            if (majEle == nums[i]) {
                count++;
            } else
                count--;
        }
        return majEle;
    }
};