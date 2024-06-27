class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> centerFreq;

        for (auto it : edges) {
            centerFreq[it[0]]++;
            centerFreq[it[1]]++;
        }
        for (auto it : centerFreq) {
            if (it.second == centerFreq.size() - 1) {
                return it.first;
            }
        }
        return -1;
    }
};