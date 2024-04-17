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
    void traverse(TreeNode* root, string& ans, string& curr) {
        if(root == NULL) return;
        curr += char('a' + root->val);

        if(root->left == NULL && root->right == NULL) {
            reverse(curr.begin(), curr.end());
            if(ans == "") ans = curr;
            else ans = min(ans, curr);
            reverse(curr.begin(), curr.end());
        }

        traverse(root->left, ans, curr);
        traverse(root->right, ans, curr);
        curr.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string curr = "";
        traverse(root, ans, curr);

        return ans;
    }
};