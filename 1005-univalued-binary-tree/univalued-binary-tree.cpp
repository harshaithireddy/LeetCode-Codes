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
private:
    void Solve(TreeNode* root, int target, bool& flag) {
        if(root == NULL) return;
        if(root->val != target) {
            flag = false;
            return;
        }
        Solve(root->left, target, flag);
        Solve(root->right, target, flag);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        int target = root->val;
        bool flag = true;
        Solve(root, target, flag);

        return flag;
    }
};