/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        vector<vector<int>> result(m, vector<int>(n, -1));
        if (!head)
            return result;
        ListNode* curr = head;
        while (top <= bottom && left <= right && curr != nullptr) {

            for (int i = left; i <= right && curr != nullptr; ++i) {
                result[top][i] = curr->val;
                curr = curr->next;
            }
            top++;

            for (int i = top; i <= bottom && curr != nullptr; ++i) {
                result[i][right] = curr->val;
                curr = curr->next;
            }
            right--;

            if (top <= bottom && curr != nullptr) {
                for (int i = right; i >= left && curr != nullptr; i--) {
                    result[bottom][i] = curr->val;
                    curr = curr->next;
                }
                bottom--;
            }

            if (left <= right && curr != nullptr) {
                for (int i = bottom; i >= top && curr != nullptr; i--) {
                    result[i][left] = curr->val;
                    curr = curr->next;
                }
                left++;
            }
        }
        return result;
    }
};