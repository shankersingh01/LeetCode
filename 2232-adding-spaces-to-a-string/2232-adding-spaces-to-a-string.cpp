class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result(s.size() + spaces.size(), ' ');

        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (j < spaces.size() && i == spaces[j]) {
                ++j;
            }
            result[i + j] = s[i];
        }
        return result;
    }
};