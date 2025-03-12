class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int left = 0, right = nums.size();

        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    int maximumCount(vector<int>& nums) {
        int negCount = lowerBound(nums, 0);
        int posIndex = lowerBound(nums, 1);
        int posCount = nums.size() - posIndex;
        return max(posCount, negCount);
    }
};