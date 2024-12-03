class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        int i = 0, j = 0;
        while (i < s.size() && j < spaces.size()) {
            if (i != spaces[j]) {
                result += s[i];
            } else if (i == spaces[j]) {
                result += " ";
                i--;
                j++;
            }
            i++;
        }
        while (i <= s.size() - 1) {
            result += s[i];
            i++;
        }

        return result;
    }
};