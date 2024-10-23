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
    TreeNode* bfs(TreeNode* root) {
        if (!root)
            return nullptr;

        queue<TreeNode*> q;
        int prevValue = root->val;
        q.push(root);

        while (!q.empty()) {
            int qSize = q.size();
            int currSum = 0;

            while (qSize > 0) {
                TreeNode* currNode = q.front();
                q.pop();

                int leftRightSum = (currNode->left ? currNode->left->val : 0) +
                                   (currNode->right ? currNode->right->val : 0);

                if (currNode->left) {
                    currNode->left->val = leftRightSum;
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    currNode->right->val = leftRightSum;
                    q.push(currNode->right);
                }

                currSum += leftRightSum;
                currNode->val = prevValue - currNode->val;
                qSize--;
            }
            prevValue = currSum;
        }
        return root;
    }

    TreeNode* copyTree(TreeNode* root) {
        if (!root)
            return nullptr;

        TreeNode* newNode = new TreeNode(root->val);
        newNode->left = copyTree(root->left);
        newNode->right = copyTree(root->right);

        return newNode;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode* duplicateTree = copyTree(root);
        return bfs(duplicateTree);
    }
};