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
void LevelOrder(TreeNode* root, vector<vector<int>>& res) {
    if(root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> V;
        while(size > 0) {
            TreeNode* node = q.front();
            V.push_back(node->val);
            q.pop();

            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);

            size--;
        }
        res.push_back(V);
    }
}
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        LevelOrder(root, res);

        reverse(res.begin(), res.end());
        return res;
    }
};