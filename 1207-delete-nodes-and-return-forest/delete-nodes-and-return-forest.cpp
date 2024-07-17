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
    vector<TreeNode*> res;
    void dfs(TreeNode* root, unordered_set<int>& st, bool isRoot) {
        if(root == NULL) return;

        if(st.find(root->val) != st.end()) {
            dfs(root->left, st, true);
            dfs(root->right, st, true);
        }
        else {
            if(isRoot == true) res.push_back(root);

            TreeNode* leftNode = root->left;
            TreeNode* rightNode = root->right;

            if(root->left != NULL) {
                if(st.find(root->left->val) != st.end()) root->left = NULL;
            }
            if(root->right != NULL) {
                if(st.find(root->right->val) != st.end()) root->right = NULL;
            }

            dfs(leftNode, st, false);
            dfs(rightNode, st, false);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        dfs(root, st, true);

        return res;
    }
};