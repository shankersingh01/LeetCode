class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        bitset<100000> visited = 0; // to store the visited node
        for (auto& it : edges) {
            int first = it[0], second = it[1];
            if (visited[first]) // check if the first node is already visited
                return first;
            if (visited[second]) // check if the second node is already visited
                return second;
            visited.set(first);
            visited.set(second);
        }
        return -1;
    }
};