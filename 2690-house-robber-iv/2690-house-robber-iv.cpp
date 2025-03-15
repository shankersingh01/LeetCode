class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int mid){
        int kHouseCount = 0;

        for(int i=0; i<nums.size(); ++i){
            if(nums[i] <= mid){
                kHouseCount++;
                i++;
            } 
            if(kHouseCount >= k) return true;
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = 0;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(isPossible(nums,k,mid)){
                result = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return result;
    }
};