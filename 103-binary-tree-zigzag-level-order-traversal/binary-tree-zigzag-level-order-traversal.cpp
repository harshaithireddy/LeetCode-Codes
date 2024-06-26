/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        bool flag = true;

        while(!q.empty()) {
            int size = q.size();
            vector<int> v;

            while(size > 0) {
                TreeNode* node = q.front();
                v.push_back(node->val);
                q.pop();

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);

                size--;
            }
            if(flag == true) ans.push_back(v);
            else {
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
            flag = !flag;
        }
        return ans;
    }
};