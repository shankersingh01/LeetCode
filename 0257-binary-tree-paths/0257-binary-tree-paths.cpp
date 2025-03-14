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
    void helper(TreeNode* root, vector<string>& result, string str) {
        if (!root)
            return;
        if (!str.empty())
            str += "->" + to_string(root->val);
        else
            str += to_string(root->val);

        if (!root->left && !root->right) {
            result.push_back(str);
            str = "";
        }

        helper(root->left, result, str);
        helper(root->right, result, str);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string str = "";
        helper(root, result, str);
        return result;
    }
};