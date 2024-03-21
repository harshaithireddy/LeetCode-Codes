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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left >= right) return head;

        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        for(int i = 0; i < left-1; i++) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* leftPrev = prev;
        prev = NULL;

        for(int i = 0; i < right-left+1; i++) {
            ListNode* tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }

        leftPrev->next->next = curr;
        leftPrev->next = prev;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};