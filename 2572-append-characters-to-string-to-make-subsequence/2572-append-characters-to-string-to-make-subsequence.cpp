class Solution {
public:
    int appendCharacters(string s, string t) {
        int sStart = 0, tStart = 0;
        int sEnd = s.size(), tEnd = t.size();

        while (sStart < sEnd && tStart < tEnd) {
            if (s[sStart] == t[tStart]) {
                tStart++;
            }
            sStart++;
        }
        return tEnd - tStart;
    }
};