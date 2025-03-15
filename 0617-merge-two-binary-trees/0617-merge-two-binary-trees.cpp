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
    TreeNode* dfs(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return nullptr;
        TreeNode* node;
        if (root1 && root2) {
            node = new TreeNode(root1->val + root2->val);
            node->left = dfs(root1->left, root2->left);
            node->right = dfs(root1->right, root2->right);
        } else if (root1) {
            node = new TreeNode(root1->val);
            node->left = dfs(root1->left, nullptr);
            node->right = dfs(root1->right, nullptr);
        } else {
            node = new TreeNode(root2->val);
            node->left = dfs(nullptr, root2->left);
            node->right = dfs(nullptr, root2->right);
        }
        return node;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return nullptr;
        TreeNode* resultNode = dfs(root1, root2);
        return resultNode;
    }
};