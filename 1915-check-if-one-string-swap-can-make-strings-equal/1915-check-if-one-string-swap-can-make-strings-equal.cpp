class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int misPlacedCharCount = 0;
        vector<int> freq(26, 0);

        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                misPlacedCharCount++;
            }
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return misPlacedCharCount <= 2 ? true : false;
    }
};