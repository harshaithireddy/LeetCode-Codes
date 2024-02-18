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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;

        while(l1 != NULL || l2 != NULL) {
            int x, y;
            if(l1 != NULL) x = l1->val;
            else x = 0;

            if(l2 != NULL) y = l2->val;
            else y = 0;

            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        if(carry > 0) {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};