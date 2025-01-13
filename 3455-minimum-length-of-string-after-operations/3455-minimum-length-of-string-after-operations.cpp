class Solution {
public:
    int minimumLength(string s) {
        int strLen = s.size();
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        int removedChars = 0;

        for (auto x : mp) {
            if (x.second >= 3) {
                if (x.second % 2 == 0) {
                    removedChars += (x.second - 2);
                }
                else removedChars += (x.second - 1);
            }
            
        }

        return strLen - removedChars;
    }
};