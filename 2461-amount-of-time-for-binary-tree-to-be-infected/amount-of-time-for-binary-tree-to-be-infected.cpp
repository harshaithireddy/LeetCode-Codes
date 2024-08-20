/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int TimeCalculate(unordered_map<TreeNode*, TreeNode*>& m, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(target);

        map<TreeNode*, int> vis;
        vis[target] = 1;
        int maxCnt = 0;

        while (!q.empty()) {
            int size = q.size();
            int flag = 0;

            for(int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left]) {
                    flag = 1;
                    q.push(node->left);
                    vis[node->left] = 1;
                }

                if(node->right && !vis[node->right]) {
                    flag = 1;
                    q.push(node->right);
                    vis[node->right] = 1;
                }

                if(m[node] && !vis[m[node]]) {
                    flag = 1;
                    q.push(m[node]);
                    vis[m[node]] = 1;
                }
            }
            if(flag) maxCnt += 1;
        }

        return maxCnt;
    }

    TreeNode* parentMapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;

        while (!q.empty()) {
            TreeNode* node = q.front();
            if(node->val == start) res = node;
            q.pop();

            if(node->left) {
                m[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                m[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL) return 0;
        unordered_map<TreeNode*, TreeNode*> m;
        TreeNode* target = parentMapping(root, m, start);

        int maxTime = TimeCalculate(m, target);
        return maxTime;
    }
};