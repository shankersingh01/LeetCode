class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (int i = 0; i < word.size(); ++i) {
            freq[word[i] - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());

        int totalButtonPushed = 0;
        int limit = 8;
        int buttonPushReq = 1;
        
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) {
                break;
            }
            totalButtonPushed += freq[i] * buttonPushReq;
            limit--;
            if (limit == 0) {
                limit = 8;
                buttonPushReq++;
            }
        }

        return totalButtonPushed;
    }
};