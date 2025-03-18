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
    void inorderTraversal(TreeNode* root, int k, vector<int>& result) {
        if (!root)
            return;

        inorderTraversal(root->left, k, result);
        result.push_back(root->val);
        inorderTraversal(root->right, k, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        inorderTraversal(root, k, result);
        return result[k - 1];
    }
};