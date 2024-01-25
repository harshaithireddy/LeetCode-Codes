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
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = head;
        ListNode* t = dummy;

        while(temp != NULL && temp->next != NULL) {
            if(temp->val == 0) {
                ListNode* curr = temp->next;
                int sum = 0;

                while(curr != NULL && curr->val != 0) {
                    sum += curr->val;
                    curr = curr->next;
                }

                ListNode* sumNode = new ListNode(sum);
                t->next = sumNode;
                t = t->next;
                temp = curr;
            }
        }
        return dummy->next;
    }
};