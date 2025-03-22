class Solution {
public:
    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int currNode,
             int& nodeCount, int& edgeCount) {
        visited[currNode] = true;
        nodeCount++;
        edgeCount += adjList[currNode].size();
        for (int nextNode : adjList[currNode]) {
            if (!visited[nextNode]) {
                dfs(adjList, visited, nextNode, nodeCount, edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // adjacency list
        vector<vector<int>> adjList(n);

        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        int compCount = 0;
        for (int i = 0; i < n; ++i) {
            int nodeCount = 0, edgeCount = 0;
            if (!visited[i]) {
                dfs(adjList, visited, i, nodeCount, edgeCount);
                if (nodeCount * (nodeCount - 1) == edgeCount) {
                    compCount++;
                }
            }
        }
        return compCount;
    }
};