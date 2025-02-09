class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;

        unordered_map<int, int> diffMap;
        long long notBadPairCount = 0;
        for (int i = 0; i < n; ++i) {
            diffMap[nums[i] - i]++;
            if (diffMap.find(nums[i] - i) != diffMap.end()) {
                notBadPairCount += (diffMap[nums[i] - i] - 1);
                cout<<notBadPairCount<<endl;
            }   
        }
        long long result = totalPairs - notBadPairCount;
        return result;
    }
};