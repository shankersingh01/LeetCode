class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int index = -1;

        unordered_map<int, int> freq;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (freq.find(nums[i]) != freq.end()) {
                index = i;
                break;
            } else
                freq[nums[i]]++;
        }
        if(index == -1) return 0;
        index++;
        return index  % 3 ? ((index / 3) + 1) : index / 3;
    }
};