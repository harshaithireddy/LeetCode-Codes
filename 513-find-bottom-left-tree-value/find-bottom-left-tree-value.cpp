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
    int prevMax = -1;
    void Traverse(TreeNode* root, int level, int& res) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            if(level > prevMax) {
                res = root->val;
                prevMax = level;
            }
            return;
        }
        prevMax = max(prevMax, level);
        if(root->left != NULL) Traverse(root->left, level + 1, res);
        if(root->right != NULL) Traverse(root->right, level + 1, res);
    }
    int findBottomLeftValue(TreeNode* root) {
        int res = 0;
        Traverse(root, 0, res);
        return res;
    }
};