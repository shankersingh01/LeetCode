/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *temp1 = headA;
        while (temp1 != NULL) {
            ListNode* temp2 = headB;
            while (temp2 != NULL) {
                // if both nodes are same
                if (temp1 == temp2)
                    return temp1;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        // intersection is not present between the lists return null
        return NULL;
    }
};