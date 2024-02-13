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
    void Depth(TreeNode* root, int d, int& maxi) {
        if(root == NULL) {
            maxi = max(maxi, d);
            return;
        }
        Depth(root->left, d + 1, maxi);
        Depth(root->right, d + 1, maxi);
    }

    int maxDepth(TreeNode* root) {
        int maxi = 0;
        Depth(root, 0, maxi);

        return maxi;
    }
};