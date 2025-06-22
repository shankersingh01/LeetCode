class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;

        for (int i = 0; i < s.size(); i += k) {
            string temp = "";
            int j = i;
            while (temp.size() < k && j < s.size()) {
                temp += s[j++];

            }
            while (temp.size() < k) {
                temp += fill;
            }
            result.push_back(temp);
        }
        return result;
    }
};