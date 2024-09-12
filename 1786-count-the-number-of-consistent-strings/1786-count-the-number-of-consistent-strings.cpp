class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        for (auto letter : allowed) {
            mp[letter]++;
        }
        int count = 0;
        for (auto word : words) {
            int flag = 0;
            for (int i = 0; i < word.size(); ++i) {
                if (mp.find(word[i]) == mp.end()) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                count++;
            }
        }
        return count;
    }
};