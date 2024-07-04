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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* newHead = new ListNode(0);
        ListNode* tail = newHead;
        int sum = 0;
        head = head->next;
        while (head != NULL) {
            if (head->val != 0)
                sum += head->val;
            else {
                ListNode* newNode = new ListNode(sum);
                tail->next = newNode;
                tail = tail->next;
                sum = 0;
            }
            head = head->next;
        }
        return newHead->next;
    }
};