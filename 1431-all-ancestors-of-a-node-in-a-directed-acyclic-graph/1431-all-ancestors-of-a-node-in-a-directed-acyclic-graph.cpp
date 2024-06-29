class Solution {

private:
    void dfs(vector < vector<int>> & childList, int parent, int curr,
             vector < vector<int>> & ancestors, bitset<1000>& visit) {
        visit[curr] = 1;
        for (int it : childList[curr]) {
            if (!visit[it]) {
                ancestors[it].push_back(parent);
                dfs(childList, parent, it, ancestors, visit);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ancestors(n);
        vector<vector<int>> childList(n);

        for (auto& it : edges) {
            childList[it[0]].push_back(it[1]);
        }

        for (int i = 0; i < n; ++i) {
            bitset<1000> visit = {0};
            dfs(childList, i, i, ancestors, visit);
        }

        for (int i = 0; i < n; ++i) {
            sort(ancestors[i].begin(), ancestors[i].end());
        }
        return ancestors;
    }
};