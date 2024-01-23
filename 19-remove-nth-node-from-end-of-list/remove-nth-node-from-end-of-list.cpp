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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        if(head->next == NULL && n == 1) return NULL;


        int size = 1;
        ListNode* temp = head;
        
        while(temp->next != NULL) {
            size++;
            temp = temp->next;
        }

        if(n == size) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        

        temp = head;

        int cnt = size - n;
        for(int i = 1; i < cnt; i++) {
            temp = temp->next;
        }
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};