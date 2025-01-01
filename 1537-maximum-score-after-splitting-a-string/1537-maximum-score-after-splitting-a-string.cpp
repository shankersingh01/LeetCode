class Solution {
public:
    int maxScore(string s) {
        int rightCount = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '1') rightCount++;
        }
        int leftCount = 0;
        int maxScore = 0;
        for(int i=0; i<s.size()-1; ++i){
            if(s[i] == '0') leftCount++;
            else if(s[i] == '1') rightCount--;
            maxScore = max(maxScore, leftCount + rightCount);
        }
        return maxScore;
    }
};