/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void helper(vector<vector<int>>& result, vector<int>& validPath, TreeNode* root, int currSum, int targetSum){
        if(!root) return;

        currSum += root->val;
        validPath.push_back(root->val);

        if(!root->left && !root->right && currSum == targetSum){
            result.push_back(validPath);
        }

        helper(result, validPath, root->left, currSum, targetSum);
        helper(result, validPath, root->right, currSum, targetSum);

        validPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> validPath;
        helper(result, validPath, root, 0, targetSum);
        return result;
    }
};