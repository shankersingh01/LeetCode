class Solution {
public:
    bool check(vector<int>& nums) {
        int misplacedNum = 0;
        int numsSize = nums.size();
        
        for (int i = 0; i < numsSize; ++i) {
            if (nums[i] > nums[(i + 1) % numsSize]) {
                misplacedNum++;
                if (misplacedNum > 1)
                    return false;
            }
        }
        return true;
    }
};