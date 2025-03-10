class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int countVowelSubstrings(string word) {
        unordered_map<char, int> freq;
        int subCount = 0;
        for (int i = 0; i < word.size(); ++i) {
            freq.clear();
            for (int j = i; j < word.size() && isVowel(word[j]); ++j) {
                freq[word[j]]++;
                if (freq.size() >= 5)
                    subCount++;
            }
        }
        return subCount;
    }
};