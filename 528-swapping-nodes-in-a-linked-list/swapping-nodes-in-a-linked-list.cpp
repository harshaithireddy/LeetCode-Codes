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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        temp = head;
        ListNode* kthFromBegin = NULL;
        for (int i = 1; i < k; ++i) {
            temp = temp->next;
        }
        kthFromBegin = temp;

        temp = head;
        ListNode* kthFromEnd = NULL;
        for (int i = 0; i < n - k; ++i) {
            temp = temp->next;
        }
        kthFromEnd = temp;

        swap(kthFromBegin->val, kthFromEnd->val);

        return head;

    }
};