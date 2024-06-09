class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int numSize = nums.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < numSize; ++i) {
            freq[nums[i]]++;
        }
        vector<int> singleNum;
        for (auto num : freq) {
            if (num.second == 1) {
                singleNum.push_back(num.first);
            }
        }
        return singleNum;
    }
};