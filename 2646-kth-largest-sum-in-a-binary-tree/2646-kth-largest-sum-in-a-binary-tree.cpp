/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* root, int k, vector<long long>& result) {
        if (!root)
            return;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            long long levelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();
                levelSum += (long long)current->val;
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
            result.push_back(levelSum);
        }
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> result;
        bfs(root, k, result);
        if(k > result.size()) return -1;
        sort(result.begin(), result.end(), greater<long long>());
        return result[k - 1];
    }
};