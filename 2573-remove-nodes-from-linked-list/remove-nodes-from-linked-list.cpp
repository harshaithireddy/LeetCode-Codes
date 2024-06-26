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
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        stack<int> st;
        ListNode* temp = head;
        
        while(temp != NULL) {
            int x = temp->val;
            if(st.empty() || st.top() >= x) {
                st.push(x);
            }
            else {
                while(!st.empty() && st.top() < x) {
                    st.pop();
                }
                st.push(x);
            }
            temp = temp->next;
        }

        ListNode* newHead = NULL;
        while(!st.empty()) {
            ListNode* newNode = new ListNode(st.top());
            st.pop();
            newNode->next = newHead;
            newHead = newNode;
        }
        return newHead;
    }
};