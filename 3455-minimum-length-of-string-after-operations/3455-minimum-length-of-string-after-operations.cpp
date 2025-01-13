class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        int minLen = 0;

        for (auto x : mp) {
            while (x.second >= 3) {
                x.second -= 2;
            }
            minLen += x.second;
        }

        return minLen;
    }
};