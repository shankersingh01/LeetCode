class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mpp;

        for (int num : arr1) {
            while (num > 0) {

                mpp[to_string(num)]++;
                num = num / 10;
            }
        }
        int longestPrefix = 0;
        for (int num : arr2) {
            string prefix = to_string(num);
            int len = prefix.size();
            while (len > 0) {
                if (mpp.find(prefix) != mpp.end()) {
                    longestPrefix = max(longestPrefix, len);
                    break;
                }
                len--;
                prefix = prefix.substr(0, len);
            }
        }
        return longestPrefix;
    }
};
