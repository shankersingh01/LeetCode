class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxValue = 0, maxDiff = 0, maxElement = 0;

        for (const long long& num : nums) {
            maxValue = max(maxValue, maxDiff * num);
            maxDiff = max(maxDiff, maxElement - num);
            maxElement = max(maxElement, num);
        }
        return maxValue;
    }
};