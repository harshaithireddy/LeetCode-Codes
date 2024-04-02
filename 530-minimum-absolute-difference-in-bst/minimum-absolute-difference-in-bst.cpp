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
    int prev = -1;
    int minDifference = INT_MAX;
    void solver(TreeNode* root) {
        if(root == NULL) return;
        solver(root->left);
        if(prev != -1) minDifference = min(minDifference, root->val - prev);
        if(root != NULL) prev = root->val;
        solver(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solver(root);
        return minDifference;
    }
};