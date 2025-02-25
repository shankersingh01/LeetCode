class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0, prefixSum = 0;
        const int MOD = 1000000007;
        for(int num : arr) {
            prefixSum += num;
            oddCount += prefixSum % 2;
        }
        oddCount += (arr.size() - oddCount) * oddCount;
        return oddCount % MOD;
    }
};