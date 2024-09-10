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
private:
    int GCD(int a, int b) {
        if(b == 0) {
            return a;
        }
        return GCD(b, a % b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL) {
            int gcd = GCD(temp->val, temp->next->val);
            ListNode* gcdNode = new ListNode(gcd);
            gcdNode->next = temp->next;
            temp->next = gcdNode;
            temp = temp->next->next;
        }
        return head;
    }
};