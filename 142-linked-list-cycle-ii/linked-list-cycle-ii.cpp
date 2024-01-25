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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) break;
        }

        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        ListNode* temp1 = slow;
        ListNode* temp2 = head;

        while(temp1 != NULL) {
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return nullptr;
    }
};