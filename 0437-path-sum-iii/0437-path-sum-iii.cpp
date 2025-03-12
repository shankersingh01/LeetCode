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
    int validPathCount = 0;

    void dfs(TreeNode* root, long long sum, int targetSum) {
        if (!root)
            return;
        sum += root->val;
        if (sum == targetSum) {
            validPathCount++;
        }
        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        long long sum = 0;
        dfs(root, sum, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return validPathCount;
    }
};