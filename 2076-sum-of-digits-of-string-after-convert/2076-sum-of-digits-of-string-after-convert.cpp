class Solution {
public:
    int getLucky(string s, int k) {
        // Converting alphabet to int
        string num = "";
        for (int i = 0; i < s.size(); ++i) {
            num += to_string(s[i] - 'a' + 1);
        }

        // adding all the numbers in the string
        for (int i = 1; i <= k; ++i) {
            int sum = 0;
            for (int j = 0; j < num.size(); ++j) {
                sum += num[j] - '0';
            }
            num = to_string(sum);
        }
        int result = std::stoi(num);
        return result;
    }
};