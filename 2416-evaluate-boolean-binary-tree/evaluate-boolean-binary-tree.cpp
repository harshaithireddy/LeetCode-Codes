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
    bool traverse(TreeNode* root) {
        if(root->val == 0) return false;
        else if(root->val == 1) return true;
        else if(root->val == 2) return traverse(root->left) || traverse(root->right);
        else if(root->val == 3) return traverse(root->left) && traverse(root->right);
        else return true;
    }
    bool evaluateTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        return traverse(root);
    }
};