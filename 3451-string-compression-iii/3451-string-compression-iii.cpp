class Solution {
public:
    string compressedString(string word) {
        string result = "";
        int count = 1;
        for (int i = 0; i < word.size() - 1; ++i) {
            if (word[i] != word[i + 1] || count >= 9) {
                result += to_string(count) + word[i];
                count = 1;
            } else
                count++;
        }

        result += to_string(count) + word[word.size() - 1];

        return result;
    }
};