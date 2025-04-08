class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int index = -1;

        unordered_map<int, int> freq;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (freq.find(nums[i]) != freq.end()) {
                i++;
                return i % 3 ? ((i / 3) + 1) : i / 3;
            } else
                freq[nums[i]]++;
        }
        return 0;
        
    }
};