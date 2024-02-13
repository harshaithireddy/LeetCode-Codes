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
    void LeftSum(TreeNode* root, int left, int& sum) {
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL) {
            if(left == 1)
                sum += root->val;
        }
        
        LeftSum(root->left, left = 1, sum);
        LeftSum(root->right, left = 0, sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        LeftSum(root, -1, sum);

        return sum;
    }
};