class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> indexMap;

        for (int i = 0; i < s.size(); ++i) {
            indexMap[s[i]] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        int newStart = left;
        while (left < s.size()) {
            right = max(indexMap[s[left]], right);
            if (left == right) {
                result.push_back(right - newStart + 1);
                newStart = left + 1;
            }
            left++;
        }
        return result;
    }
};