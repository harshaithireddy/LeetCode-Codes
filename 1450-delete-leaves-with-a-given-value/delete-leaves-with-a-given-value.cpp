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
    bool isLeaf(TreeNode* node) {
        if(node == NULL) return false;
        if(node->left == NULL && node->right == NULL) return true;
        return false;
    }
    void traverse(TreeNode* root, int target) {
        if(root == NULL) return;
        traverse(root->left, target);
        traverse(root->right, target);

        if(isLeaf(root->left) && root->left->val == target) {
            root->left = NULL;
        }
        if(isLeaf(root->right) && root->right->val == target) {
            root->right = NULL;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    
        traverse(root, target);
        if(root->left == NULL && root->right == NULL && root->val == target) {
            return NULL;
        }
        return root;
    }
};