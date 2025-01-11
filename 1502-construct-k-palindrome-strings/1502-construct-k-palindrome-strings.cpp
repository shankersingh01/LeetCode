class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;

        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]]++;
        }

        int oddCount = 0;

        for (auto ch : mp) {
            if (ch.second % 2 == 1) {
                oddCount++;
            }
        }
        if (oddCount > k) {
            return false;
        }
        return true;
    }
};