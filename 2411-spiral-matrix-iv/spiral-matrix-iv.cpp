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
    int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int> (n, -1));
        if(m == 0 || n == 0) return res;
        
        ListNode* temp = head;
        int i = 0, j = 0, di = 0;
        for(int k = 0; k < m * n && temp != NULL; k++) {
            res[i][j] = temp->val;
            temp = temp->next;

            int ni = i + dirs[di].first;
            int nj = j + dirs[di].second;

            if(ni < 0 || ni >= m || nj < 0 || nj >= n || res[ni][nj] != -1) {
                di = (di + 1) % 4;
                ni = i + dirs[di].first;
                nj = j + dirs[di].second;
            }
            i = ni;
            j = nj;
        }
        return res;
    }
};