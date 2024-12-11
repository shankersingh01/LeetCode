class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        int sameElementPossibleCount = 0;
        while(right < nums.size()){
            if(nums[right] - nums[left] > 2 * k){
                left++;
            }
            sameElementPossibleCount = max(sameElementPossibleCount, right-left + 1);
            right++;
        }
        return sameElementPossibleCount;
    }
};
