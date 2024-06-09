class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMap;
        int count = 0;
        int prefixSum = 0;
        prefixMap[0] = 1;

        for (int num : nums) {
            prefixSum += num;
            int rem = prefixSum % k;

            if (rem < 0) {
                rem += k;
            }
            if (prefixMap.find(rem) != prefixMap.end()) {
                count+=prefixMap[rem];
                prefixMap[rem]++;
            } else {
                prefixMap[rem] = 1;
            }
        }
        return count;
    }
};