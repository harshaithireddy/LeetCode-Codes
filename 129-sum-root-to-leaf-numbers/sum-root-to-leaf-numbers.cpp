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
    void Traverse(TreeNode* root, int currSum, int &res) {
        if(root == NULL) return;
        currSum = currSum * 10 + root->val;

        if(root->left == NULL && root->right == NULL) res += currSum;
        Traverse(root->left, currSum, res);
        Traverse(root->right, currSum, res);
    }
    int sumNumbers(TreeNode* root) {
        int currSum = 0;
        int res = 0;
        Traverse(root, currSum, res);

        return res;
    }
};