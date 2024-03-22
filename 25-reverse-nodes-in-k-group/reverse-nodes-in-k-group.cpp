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
    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    ListNode* kthNode(ListNode* temp, int k) {
        k--;
        while(temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    } 
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp != NULL) {
            ListNode* kth = kthNode(temp, k);
            if(kth == NULL) {
                if(prevLast) prevLast->next = temp;
                break;
            }
            ListNode* next = kth->next;
            kth->next = NULL;

            reverseLL(temp);
            if(temp == head) head = kth;
            else prevLast->next = kth;

            prevLast = temp;
            temp = next;
        }
        return head;
    }
};