class Solution {
public:
    string makeFancyString(string s) {
        int sSize = s.size();
        string result = "";

        if (sSize > 0) {
            result += s[0];
        }

        int sameCharCount = 1;

        for (int i = 1; i < sSize; ++i) {
            if (s[i] != result.back()) {
                result += s[i];
                sameCharCount = 1;
            } else if (s[i] == result.back() && sameCharCount < 2) {
                sameCharCount++;
                result += s[i];
            }
        }
        return result;
    }
};