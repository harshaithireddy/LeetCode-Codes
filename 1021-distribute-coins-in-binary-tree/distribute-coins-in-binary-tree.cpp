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
    int traverse(TreeNode* root, int& res) {
        if(root == NULL) return 0;

        int left = traverse(root->left, res);
        int right = traverse(root->right, res);

        res += (abs(left) + abs(right));

        return ((root->val - 1) + left + right);
    }
    int distributeCoins(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int res = 0;
        traverse(root, res);

        return res;
    }
};