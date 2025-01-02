class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        // create a vector to store the count of valid string upto that index
        // and then based upon the range just return the count
        vector<int> vowelStr;
        int vowelStrCount = 0;
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
        for (string str : words) {
            if (vowelSet.find(str[0]) != vowelSet.end() && vowelSet.find(str[str.size() - 1]) != vowelSet.end()) {
                vowelStrCount++;
            }
            vowelStr.push_back(vowelStrCount);
        }

        vector<int> result;

        for (const auto& query : queries) {
            if (query[0] < 1) {
                result.push_back(vowelStr[query[1]]);
            } else {
                result.push_back(vowelStr[query[1]] - vowelStr[query[0] - 1]);
            }
        }
        return result;
    }
};