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
    static int minimumOperations(TreeNode* treeRoot) {
        queue<TreeNode*> levelQueue; // Queue for BFS traversal
        levelQueue.push(treeRoot);
        int totalSwaps = 0; // Count of swaps needed across all levels

        while (!levelQueue.empty()) {
            int levelSize =
                levelQueue.size(); // Number of nodes in the current level
            vector<int> sortedIndices(levelSize, 0);
            iota(sortedIndices.begin(), sortedIndices.end(),
                 0); // Initialize indices
            vector<int> levelValues(levelSize, 0);

            for (int currentIndex = 0; currentIndex < levelSize;
                 currentIndex++) {
                auto currentNode = levelQueue.front();
                levelQueue.pop();
                levelValues[currentIndex] =
                    currentNode->val; // Store node value

                // Add left and right children to the queue
                if (currentNode->left)
                    levelQueue.push(currentNode->left);
                if (currentNode->right)
                    levelQueue.push(currentNode->right);
            }

            // Sort indices based on the corresponding node values
            sort(sortedIndices.begin(), sortedIndices.end(),
                 [&](int i, int j) { return levelValues[i] < levelValues[j]; });

            // Count the number of swaps needed to sort the indices
            for (int currentIndex = 0; currentIndex < levelSize;) {
                int targetIndex = sortedIndices[currentIndex];
                if (targetIndex != currentIndex) { // Swap if out of place
                    totalSwaps++;
                    swap(sortedIndices[currentIndex],
                         sortedIndices[targetIndex]);
                } else {
                    currentIndex++; // Move to the next index
                }
            }
        }
        return totalSwaps;
    }
};
