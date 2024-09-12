class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bitset<26> allowedBits;

        for (char c : allowed) {
            allowedBits[c - 'a'] = 1;
        }

        int count = 0;
        for (string& word : words) {
            int consistent = 1;
            for (char c : word) {
                if (allowedBits[c - 'a'] == 0) {
                    consistent = 0;
                }
            }
            count += consistent;
        }
        return count;
    }
};