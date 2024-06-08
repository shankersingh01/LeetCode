class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (auto i : s) {
            freq[i]++;
        }
        int totalCount=0;
        int oddCount=0;
        for (auto x : freq) {
            if (x.second % 2 == 0) {
                totalCount += x.second;
            }
            else{
                totalCount+=x.second-1;
                oddCount=1;
            }
        }
        totalCount += oddCount;
        return totalCount;
    }
};