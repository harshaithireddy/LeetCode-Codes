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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;

        ListNode* temp = head;
        int n = 1;
        
        while(temp->next != NULL) {
            n++;
            temp = temp->next;
        }

        k = k % n;
        if(n == k || k == 0) return head;

        int rotate = n - k;
        ListNode* curr = head;
        temp->next = head;

        for(int i = 1; i < rotate; i++) {
            curr = curr->next;
        }

        head = curr->next;
        curr->next = NULL;

        return head;
    }
};