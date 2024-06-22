class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        countMap[0] = 1;
        int niceCount = 0, oddCount = 0;
        for (int num : nums) {
            oddCount += num & 1;
            if (oddCount - k >= 0) {
                niceCount += countMap[oddCount - k];
            }
            countMap[oddCount]++;
        }
        return niceCount;
    }
};