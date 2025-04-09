class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minEle = *min_element(nums.begin(), nums.end());

        if (k > minEle)
            return -1;

        vector<int> freq(101, 0);
        int biggerNumCount = 0;
        for (int& num : nums) {
            if (freq[num] == 0 && num != k) {
                biggerNumCount++;
            }
            freq[num]++;
        }
        return biggerNumCount;
    }
};