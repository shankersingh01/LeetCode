class Solution {
public:
    string answerString(string s, int n) {
        if (n == 1)
            return s;
        int m = s.length();
        int i = 0, l = m - n + 1;
        string ans = s.substr(i, l);
        while (i < m) {
            string tmp = s.substr(i, l);
            if (tmp > ans)
                ans = tmp;
            i++;
        }
        return ans;
    }
};
