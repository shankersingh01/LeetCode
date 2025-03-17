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
    int convertToDecimal(string str){
        int decimalNum = stoi(str,0,2);
        return decimalNum;
    }

    void dfs(TreeNode* root, string str, int& result){
        if(!root) return;

        str += to_string(root->val);
        if(!root->left && !root->right){
            result += convertToDecimal(str);
            return;
        }
        dfs(root->left, str, result);
        dfs(root->right, str, result);
    }

    int sumRootToLeaf(TreeNode* root) {
        int result = 0;
        dfs(root, "", result);

        return result;
    }
};