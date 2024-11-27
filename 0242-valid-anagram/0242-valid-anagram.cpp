class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<int> anagram(26, 0);

        for (int i = 0; i < s.size(); ++i) {
            anagram[s[i] - 'a']++;
            anagram[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (anagram[i] > 0)
                return false;
        }
        return true;
    }
};