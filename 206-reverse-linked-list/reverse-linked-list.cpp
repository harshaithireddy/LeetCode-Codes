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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* Dummy = new ListNode(-1);

        while(temp != NULL) {
            ListNode* x = new ListNode(temp->val);
            if(Dummy->next == NULL) {
                Dummy->next = x;
            }
            else {
                x->next = Dummy->next;
                Dummy->next = x;
            }
            temp = temp->next;
        }
        return Dummy->next;
    }
};