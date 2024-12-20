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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int treeLvl = 0;
        while (!q.empty()) {
            int qSize = q.size();
            vector<int> nodes;
            queue<TreeNode*> temp = q;
            for (int i = 0; i < qSize; ++i) {
                auto it = q.front();
                q.pop();
                if (it->left)
                    q.push(it->left);
                if (it->right)
                    q.push(it->right);
                nodes.push_back(it->val);
            }

            if (treeLvl % 2 != 0) {
                reverse(nodes.begin(), nodes.end());
                int i = 0;
                while (qSize--) {
                    auto it = temp.front();
                    temp.pop();
                    it->val = nodes[i];
                    i++;
                }
            }
            treeLvl++;
        }
        return root;
    }
};