class Solution {
public:
    string clearDigits(string s) {
        string ans = "";

        for (char ch : s) {
            char checkChar = ch - 'a';
            if (checkChar >= 0 && checkChar < 26) {
                ans += ch;
            } else
                ans.pop_back();
        }
        return ans;
    }
};