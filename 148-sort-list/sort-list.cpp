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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> V;
        while(temp != NULL) {
            V.push_back(temp->val);
            temp = temp->next;
        }
        sort(V.begin(), V.end());
        temp = head;
        int i = 0;
        while(temp != NULL) {
            temp->val = V[i++];
            temp = temp->next;
        }
        return head;
    }
};