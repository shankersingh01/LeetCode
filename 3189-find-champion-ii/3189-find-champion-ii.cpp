class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> nodes(n, 0);

        for (auto& edge : edges) {
            nodes[edge[1]] = 1;
        }

        int champion = -1;
        for (int i=0; i<n; ++i) {
            if (nodes[i] == 0) {
                if (champion != -1)
                    return -1;
                else
                    champion = i;
            }
        }
        return champion;
    }
};