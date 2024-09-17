class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mpp1;
        unordered_map<string, int> mpp2;

        stringstream ss1(s1);
        stringstream ss2(s2);
        string word;

        vector<string> uncommonWord;

        while (ss1 >> word) {
            mpp1[word]++;
        }

        while (ss2 >> word) {
            mpp2[word]++;
        }

        for (const auto& x : mpp1) {
            if (x.second < 2) {
                if (mpp2.find(x.first) == mpp2.end()) {
                    uncommonWord.push_back(x.first);
                }
            }
        }

        for (const auto& x : mpp2) {
            if (x.second < 2) {
                if (mpp1.find(x.first) == mpp1.end()) {
                    uncommonWord.push_back(x.first);
                }
            }
        }
        return uncommonWord;
    }
};