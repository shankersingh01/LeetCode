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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> mask;

        for (int i = 0; i < nums.size(); ++i) {
            mask.set(nums[i]);
        }

        ListNode* curr = head;
        ListNode head2(0, head);
        ListNode *prev = &head2, *temp = NULL;
        while (curr != nullptr) {
            if (mask[curr->val] == 1) {
                prev->next = curr->next;
                temp = curr;
                curr=curr->next;
                delete temp;
                
            } else {
                prev = curr;
                temp = NULL;
                curr=curr->next;
            }
        }
        return head2.next;
    }
};