class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        for(char c : s){
            freq[c - 'a']++;
        }
        int maxOdd = INT_MIN, minEven = INT_MAX;
        for(int x : freq){
            if(x % 2 == 1 && x >= maxOdd){
                maxOdd = x;
            }
            if(x % 2 == 0 && x <= minEven && x > 0){
                minEven = x;
            }
        }
        return maxOdd - minEven;
    }
};