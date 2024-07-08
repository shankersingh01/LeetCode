class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1)
            return 1;
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }

        while (q.size() > 1) {
            for (int i = 1; i < k; ++i) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};