class Solution {
public:
    int possibleStringCount(string word) {
        int result = 0;

        vector<int> freq(26, 0);

        for (int i = 0; i < word.size(); ++i) {       
            if (++freq[word[i] - 'a'] > 1 && word[i] == word[i-1] && i > 0) {
                result++;
            }
        }
        return result + 1;
    }
};