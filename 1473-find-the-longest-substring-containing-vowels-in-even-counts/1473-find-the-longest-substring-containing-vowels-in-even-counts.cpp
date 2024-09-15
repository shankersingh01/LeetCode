class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> mpp(32,-2);
        mpp[0]=-1;
        int maxLen = 0;
        int mask = 0;
        for(int i=0; i<s.size(); ++i){
            char ch = s[i];

            switch(ch){
                case 'a':
                    mask^=1;
                    break;
                case 'e':
                    mask^=2;
                    break;
                case 'i':
                    mask^=4;
                    break;
                case 'o':
                    mask^=8;
                    break;
                case 'u':
                    mask^=16;
                    break;
            }
            int prev = mpp[mask];
            if(prev == -2){
                mpp[mask] = i;
            }
            else{
                maxLen = max(maxLen, i - prev);
            }
        }
        return maxLen;
    }
};