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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int treeHeight = 0;
        while (!q.empty()) {
            // treeHeight++;
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            treeHeight++;
        }
        return treeHeight;
    }
};