class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;
        int closeCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                openCount++;
            } else {
                if (openCount > 0) {
                    openCount--;
                } else {
                    closeCount++;
                }
            }
        }
        return openCount + closeCount;
    }
};