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
    ListNode* reverseList(ListNode* node) {
        ListNode* previous = NULL, *current = node, *nextNode;
        while (current != NULL) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        return previous;
    }
    ListNode* doubleIt(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        ListNode* reversedList = reverseList(head);
        int carry = 0;
        ListNode* current = reversedList, *previous = NULL;

        while(current != NULL) {
            int newValue = current->val * 2 + carry;
            current->val = newValue % 10;
            if(newValue > 9) {
                carry = 1;
            }
            else {
                carry = 0;
            }
            previous = current;
            current = current->next;
        }

        if(carry != 0) {
            ListNode* extraNode = new ListNode(carry);
            previous->next = extraNode;
        }

        ListNode* res = reverseList(reversedList);

        return res;
    }
};