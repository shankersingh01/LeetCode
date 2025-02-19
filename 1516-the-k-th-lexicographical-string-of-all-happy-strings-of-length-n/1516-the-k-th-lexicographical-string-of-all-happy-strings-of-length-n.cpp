class Solution {
private:
    vector<string> res;

public:
    string getHappyString(int n, int k) {
        string cur = "";
        vector<char> chars{'a', 'b', 'c'};
        dfs(cur, chars, n, k);

        return res.size() == k ? res.back() : "";
    }

    void dfs(string& cur, vector<char>& chars, int n, int k) {
        if (res.size() == k)
            return;
        if (cur.size() == n) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < 3; ++i) {
            // only append different char
            if (cur.empty() || (cur.back() != chars[i])) {
                cur.push_back(chars[i]);
                dfs(cur, chars, n, k);
                cur.pop_back();
            }
        }
    }
};