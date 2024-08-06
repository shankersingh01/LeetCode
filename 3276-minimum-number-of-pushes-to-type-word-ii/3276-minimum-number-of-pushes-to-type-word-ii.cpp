class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int i=0; i<word.size(); ++i){
            freq[word[i]-'a']++;
        }

        int totDisLetters=0;
        for(int i=0; i<26; ++i){
            if(freq[i]>0){
                totDisLetters++;
            }
        }
        int buttonPush=0;
        if(totDisLetters<=8){
            for(int i=0; i<26; ++i){
                buttonPush+=freq[i]*1;
            }
        }
        else{
            sort(freq.begin(), freq.end(), greater<int>());
            for(int i=0; i<8; ++i){
                buttonPush+=freq[i]*1;
            }
            for(int i=8; i<16; ++i){
                buttonPush+=freq[i]*2;
            }
            for(int i=16; i<24; ++i){
                buttonPush+=freq[i]*3;
            }
            for(int i=24; i<26; ++i){
                buttonPush+=freq[i]*4;
            }
        }

        return buttonPush;
    }
};