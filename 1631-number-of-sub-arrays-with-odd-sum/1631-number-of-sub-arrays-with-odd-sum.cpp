class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> oddList;
        vector<int> evenList;
        vector<int> prefixSum(arr.size(), 0);
        int oddSubArrCount = 0, sum = 0;
        const int mod = 1000000007;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            prefixSum[i] = sum;
            if (prefixSum[i] % 2 == 1) {
                oddSubArrCount = (oddSubArrCount + 1) % mod;
                oddList.push_back(prefixSum[i]);
                oddSubArrCount = (oddSubArrCount + evenList.size()) % mod;
            } else {
                evenList.push_back(prefixSum[i]);
                oddSubArrCount = (oddSubArrCount + oddList.size()) % mod;
            }
        }
        return oddSubArrCount % mod;
    }
};
