class Solution {
public:
    void dfs(int num, int n, vector<int>& result) {
        if (num > n)
            return;
        result.push_back(num);
        dfs(num * 10, n, result);
        if (num % 10 != 9)
            dfs(num + 1, n, result);
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        dfs(1, n, result);
        return result;
    }
};