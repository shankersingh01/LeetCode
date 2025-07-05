class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501, 0);

        for (int num : arr) {
            freq[num]++;
        }

        for (int i = 500; i > 0; --i) {
            if (i == freq[i])
                return i;
        }
        return -1;
    }
};