class Solution {
public:
    int maximumLength(string s) {

        unordered_map<string, int> freq;
        int maxSubstrLen = -1;

        for (int i = 0; i < s.size(); ++i) {
            string combi = "";
            for (int j = i; j < s.size(); ++j) {
                if (!combi.empty() && combi.back() == s[j]) {
                    combi += s[j];

                } else if (combi.empty()) {
                    combi += s[j];
                } else {
                    break;
                }
                freq[combi]++;
            }
        }
        for (auto& x : freq) {
            if (x.second >= 3) {
                int subStrLen = x.first.size();
                maxSubstrLen = max(maxSubstrLen, subStrLen);
            }
        }

        return maxSubstrLen;
    }
};

// string combi = "";
// for (int j = i; j < s.size(); ++j) {
//     if(combi.size() > 0 && )
//     combi += s[j];
//     freq[combi]++;
// }

// if (freq[combi] >= 3) {
//                     int combiLen = combi.size();
//                     maxSubstrLen = max(maxSubstrLen, combiLen);
//                 }
//                 left++;