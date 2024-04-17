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
    void traverse(TreeNode* root, vector<string>& ans, string curr) {
        if(root == NULL) return;
        curr += char('a' + root->val);
        if(root->left == NULL && root->right == NULL) {
            reverse(curr.begin(), curr.end());
            ans.push_back(curr);
        }
        traverse(root->left, ans, curr);
        traverse(root->right, ans, curr);

    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        traverse(root, ans, "");
        sort(ans.begin(), ans.end());

        return ans[0];
    }
};