class Solution {
public:
    bool rotateString(string s, string goal) {
        string result = s;

        if(s.length() != goal.length()) return false;

        for (int i = 0; i < result.size(); ++i) {
            if (result == goal)
                return true;
            else {
                result = result.substr(1) + result[0];
            }
        }
        return false;
    }
};