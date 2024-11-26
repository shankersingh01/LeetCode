class Solution {
public:
    int romanToInt(string s) {
        int length = s.size();

        unordered_map<char, int> mapp = {{'I', 1},   {'V', 5},   {'X', 10},
                                         {'L', 50},  {'C', 100}, {'D', 500},
                                         {'M', 1000}};

        int number = 0;
        int right = length - 1;

        while (right >= 0) {
            if ((right < length - 1) && (s[right] != s[right + 1] && mapp[s[right]] < number)) {
                number -= mapp[s[right]];
            } else
                number += mapp[s[right]];
            right--;
        }
        return number;
    }
};
