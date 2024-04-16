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
    void dfs(TreeNode* root, int val, int depth, int currDepth) {
        ios_base::sync_with_stdio(false);
        if(root == NULL) return;

        if(currDepth < depth - 1) {
            dfs(root->left, val, depth, currDepth + 1);
            dfs(root->right, val, depth, currDepth + 1);
        }

        if(currDepth == depth - 1) {
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            root->left = newLeft;
            root->right = newRight;

            newLeft->left = left;
            newRight->right = right;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newChild = root;
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = newChild;
            return newRoot;
        }

        dfs(root, val, depth, 1);
        return root;
    }
};