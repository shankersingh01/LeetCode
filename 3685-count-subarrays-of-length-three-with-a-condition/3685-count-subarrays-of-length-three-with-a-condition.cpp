class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int start = 0, end = 2;
        int count = 0;
        for(end; end < nums.size(); ++end){
            int sum = nums[start] + nums[end];
            if((double)sum == (double)nums[start + 1]/2){
                count++;
            }
            start++;
        } 
        return count;
    }
};