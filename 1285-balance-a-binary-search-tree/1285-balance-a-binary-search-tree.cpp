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

private:
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        sortedArr.push_back(root);
        inorder(root->right);
    }

    TreeNode* newBst(int start, int end) {
        if (start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* newNode = sortedArr[mid];
        newNode->left = newBst(start, mid - 1);
        newNode->right = newBst(mid + 1, end);
        return newNode;
    }

public:
    vector<TreeNode*> sortedArr;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return newBst(0, sortedArr.size() - 1);
    }
};