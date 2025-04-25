class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // find total unique numbers
        // can use set
        int k = unordered_set(nums.begin(), nums.end()).size();
        // how to check the subarray if it contains k unique numbers
        // can use map to check
        unordered_map<int, int> unique;
        int completeSubArrCount = 0, left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            unique[nums[i]]++;
            // check number of unique numbers by checking the size of the map
            while (unique.size() == k) {
                completeSubArrCount += nums.size() - i;
                unique[nums[left]]--;
                if (unique[nums[left]] == 0) {
                    unique.erase(nums[left]);
                }
                left++;
            }
        }
        return completeSubArrCount;
    }
};