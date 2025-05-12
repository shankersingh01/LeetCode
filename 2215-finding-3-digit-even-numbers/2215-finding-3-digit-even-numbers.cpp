class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

        int num = 0;
        unordered_map<int, int> freq;
        vector<int> ans;
        for (int num : digits) {
            freq[num]++;
        }

        for (int i = 100; i <= 999; ++i) {
            unordered_map<int, int> freqTemp = freq;
            int temp = i;

            while (temp > 0) {
                int digit = temp % 10;
                if (freqTemp[digit] >= 1) {
                    freqTemp[digit]--;
                } else if (freqTemp[digit] == 0) {
                    freqTemp.erase(digit);
                    break;
                }
                temp /= 10;
            }
            if (temp <= 0 && i % 2 == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};