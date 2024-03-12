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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head == NULL) return 0;

        ListNode* dummy = new ListNode(0, head);

        unordered_map<int, ListNode*> mpp;
        mpp[0] = dummy;

        int prefixSum = 0;
        while(head != NULL) {
            prefixSum += head->val;
            mpp[prefixSum] = head;
            head = head->next;
        }

        head = dummy;
        prefixSum = 0;

        while(head != NULL) {
            prefixSum += head->val;
            head->next = mpp[prefixSum]->next;
            head = head->next;
        }
        
        return dummy->next;
    }
};