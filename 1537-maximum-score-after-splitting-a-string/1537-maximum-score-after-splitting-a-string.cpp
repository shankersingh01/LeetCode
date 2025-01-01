class Solution {
public:
    int maxScore(string s) {
        int leftCount = 0;
        
        int maxScore = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            int rightCount = 0;
            if (s[i] == '0')
                leftCount++;
            for (int j = i + 1; j < s.size(); ++j) {
                if (s[j] == '1')
                    rightCount++;
            }
            maxScore = max(maxScore, leftCount + rightCount);
        }
        return maxScore;
    }
};