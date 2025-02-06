class Solution {
public:
    int fact(int pairCount) {
        if (pairCount == 0 || pairCount == 1)
            return 1;
        return pairCount * fact(pairCount - 1);
    }

    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                freq[nums[i] * nums[j]]++;
            }
        }
        int result = 0;
        for (auto x : freq) {
            if (x.second >= 2) {
                result += x.second * (x.second - 1) * 4;
            }
        }
        return result;
    }
};