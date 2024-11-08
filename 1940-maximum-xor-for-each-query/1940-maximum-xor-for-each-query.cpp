class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> prefixXor;
        int xorr = 0;
        int maxEle = pow(2, maximumBit) - 1;
        for (int i = 0; i < nums.size(); ++i) {
            xorr = xorr ^ nums[i];
            prefixXor.push_back(xorr);
            maxEle = max(maxEle, nums[i]);
        }

        vector<int> result;
        for (int i = prefixXor.size() - 1; i >= 0; i--) {
            int k = prefixXor[i] ^ maxEle;
            result.push_back(k);
        }

        return result;
    }
};
