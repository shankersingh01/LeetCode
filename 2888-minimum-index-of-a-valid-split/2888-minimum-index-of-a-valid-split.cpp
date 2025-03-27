class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (const auto& num : nums) {
            freq[num]++;
        }
        int maxFreqEle = 0;
        for (const auto& x : freq) {
            if (x.second > freq[maxFreqEle]) {
                maxFreqEle = x.first;
            }
        }

        if (freq[maxFreqEle] <= nums.size() / 2) {
            return -1;
        }

        int maxEleCount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == maxFreqEle) {
                maxEleCount++;
                if (maxEleCount > (i + 1) / 2 && freq[maxFreqEle] - maxEleCount >
                                               ((nums.size() - 1) - i) / 2) {
                    return i;
                }
                // else if(freq[maxFreqEle] - maxEleCount <= ((nums.size()-1)
                // -i)/2){
                //     return -1;
                // }
            }
        }
        return -1;
    }
};