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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        
        int n = cnt / k;
        int extra = cnt % k;

        temp = head;
        vector<ListNode*> V;

        for(int i = 0; i < k; i++) {
            ListNode* partition = temp;

            int partitionSize = -1;
            if(extra > 0) {
                partitionSize = n + 1;
                extra--;
            }
            else partitionSize = n;
            
            for(int j = 0; j < partitionSize - 1 && temp != NULL; j++) {
                temp = temp->next;
            }

            if(temp != NULL) {
                ListNode* nextNode = temp->next;
                temp->next = NULL;
                temp = nextNode;
            }

            V.push_back(partition);
        }

        return V;
    }
};