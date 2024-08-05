class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto element : arr) {
            mp[element]++;
        }
        int count = 0;
        for (auto element : arr) {
            if (mp[element] == 1) {
                count++;
                if (count == k) {
                    return element;
                }
            }
        }
        return "";
    }
};