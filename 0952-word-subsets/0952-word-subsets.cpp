class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreqWords2(26, 0);

        for (string word : words2) {
            vector<int> currCharFreq(26, 0);
            for (int i = 0; i < word.size(); ++i) {
                currCharFreq[word[i] - 'a']++;
                maxFreqWords2[word[i] - 'a'] = max(maxFreqWords2[word[i] - 'a'],
                                                   currCharFreq[word[i] - 'a']);
            }
        }
        vector<string> result;

        for (string word : words1) {
            vector<int> currCharFreq2(26, 0);
            for (int i = 0; i < word.size(); ++i) {
                currCharFreq2[word[i] - 'a']++;
            }

            bool flag = true;
            for (int i = 0; i < 26; ++i) {
                if (maxFreqWords2[i] > currCharFreq2[i]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                result.push_back(word);
            }
        }
        return result;
    }
};