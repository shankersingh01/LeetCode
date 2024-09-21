class Solution {
public:
    vector<int> result;

    void dfs(int num, int range) {
        if (num > range)
            return;
        result.push_back(num);
        num *= 10;

        for (int i = 0; i < 10; ++i) {
            dfs(num + i, range);
        }
    }

    vector<int> lexicalOrder(int n) {

        for (int i = 1; i < 10; ++i) {
            dfs(i, n);
        }

        return result;
    }
};