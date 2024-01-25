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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int cntA = 0;
        int cntB = 0;

        while(temp1 != NULL) {
            cntA++;
            temp1 = temp1->next;
        }
        while(temp2 != NULL) {
            cntB++;
            temp2 = temp2->next;
        }

        temp1 = headA;
        temp2 = headB;

        int diff = abs(cntA - cntB);
        if(cntA > cntB) {
            while(diff) {
                temp1 = temp1->next;
                diff--;
            }
        }
        else if(cntA < cntB) {
            while(diff) {
                temp2 = temp2->next;
                diff--;
            }
        }

        while(temp1 != NULL && temp2 != NULL) {
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return nullptr;
    }
};