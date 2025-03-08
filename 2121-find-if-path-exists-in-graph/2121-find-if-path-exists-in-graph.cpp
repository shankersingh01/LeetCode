class Solution {
public:
    bool dfs(vector<vector<int>>& adjList, int vertex, int destination,
             vector<int>& visited) {
        if (vertex == destination)
            return true;

        visited[vertex] = 1;

        for (int node : adjList[vertex]) {
            if (visited[node] == 0) {
                if(dfs(adjList, node, destination, visited)) return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adjList(n);

        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        return dfs(adjList, source, destination, visited);
    }
};