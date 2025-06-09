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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        bool nullNode = false;

        while(!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();

            if(!node) nullNode = true;
            else {
                if(nullNode) return false;
                Q.push(node->left);
                Q.push(node->right);
            }
        }
        return true;
    }
};