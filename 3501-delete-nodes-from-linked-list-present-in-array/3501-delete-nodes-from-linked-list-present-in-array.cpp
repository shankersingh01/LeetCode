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

        for(int i=0; i<nums.size(); ++i){
            mask.set(nums[i]);
        }

        ListNode* curr=head;
        ListNode* head2= new ListNode(0);
        ListNode* curr2 = head2;
        int count=1;
        while(curr!=nullptr){
            if(mask[curr->val]==0 ){
                curr2->next=new ListNode(curr->val);
                curr2=curr2->next;
            }   
            curr=curr->next;
        }
        return head2->next;
    }
};