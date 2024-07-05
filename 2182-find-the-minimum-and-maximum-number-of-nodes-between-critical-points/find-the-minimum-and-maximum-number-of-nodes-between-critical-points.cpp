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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        head = head->next;

        int i = 1;
        int minDist = INT_MAX;
        int prev_i = INT_MIN;
        int first = -1;

        while(head->next != NULL) {
            if((prev->val < head->val && head->val > head->next->val) || (prev->val > head->val && head->val < head->next->val)) {
                if(prev_i != INT_MIN) {
                    minDist = min(minDist, i - prev_i);
                }
                if(first == -1) first = i;
                prev_i = i;
            }
            prev = head;
            head = head->next;
            i++;
        }
        if(minDist == INT_MAX) return {-1, -1};
        return {minDist, prev_i - first};
    }
};