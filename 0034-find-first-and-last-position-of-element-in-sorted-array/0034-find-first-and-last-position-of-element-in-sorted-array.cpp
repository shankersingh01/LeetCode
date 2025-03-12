class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size();

        int first = -1, last = -1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else
                right = mid;
        }

        left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else
                right = mid;
        }

        return {first, last};
    }
};