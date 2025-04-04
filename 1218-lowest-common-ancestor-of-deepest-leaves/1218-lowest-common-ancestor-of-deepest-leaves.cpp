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
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
            return nullptr;

        int left_tree_depth = maxDepth(root->left);
        int right_tree_depth = maxDepth(root->right);

        if (left_tree_depth == right_tree_depth)
            return root;

        if (left_tree_depth > right_tree_depth)
            return lcaDeepestLeaves(root->left);
        else
            return lcaDeepestLeaves(root->right);
    }
};