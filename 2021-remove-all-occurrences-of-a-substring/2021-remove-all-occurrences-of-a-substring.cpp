class Solution {
public:
    string removeOccurrences(string s, string part) {

        string ans = "";

        for (char ch : s) {
            ans += ch;
            if (ans.size() >= part.size() && ch == part.back() &&
                ans.substr((ans.size() - part.size()), ans.size()) == part) {
                ans.erase(ans.size() - part.size());
            }
        }
        return ans;
    }
};