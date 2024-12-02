class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        for (int i = 0; i < words.size(); ++i) {
            // cout<<words[i]<<" ";
            if (words[i].size() < searchWord.size())
                continue;
            else {
                int j = 0;
                while (j < words[i].size()) {
                    if (words[i][j] != searchWord[j]) {
                        break;
                    } else {
                        j++;
                    }
                }
                if (j == searchWord.size())
                    return i + 1;
            }
        }
        return -1;
    }
};