class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCount = 0, negCount = 0;
        
        int left = 0, right = nums.size()-1;
        int firstPositive = -1, firstZero = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > 0) right = mid - 1;
            else left = mid + 1;
        }
        firstPositive = left;

        left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= 0) right = mid - 1;
            else left = mid + 1;
        }
        firstZero = left; 
        posCount = nums.size() - firstPositive;
        negCount = firstZero;
        return max(posCount , negCount);
    }
};