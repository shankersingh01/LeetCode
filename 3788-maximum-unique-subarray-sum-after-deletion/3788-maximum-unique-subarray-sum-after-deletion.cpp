class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int maxEle = INT_MIN;
        if(nums.size() < 2) return nums[0];
        for (int num : nums) {
            if (num > 0) {
                seen.insert(num);
            }
            maxEle = max(num, maxEle);
        }
        if(maxEle < 0){
            return maxEle;
        }
        int sum = 0;
        for (int num : seen) {
            sum += num;
        }
        return sum;
    }
};